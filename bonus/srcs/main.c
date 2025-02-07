/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:07:22 by vintran           #+#    #+#             */
/*   Updated: 2021/06/10 17:39:46 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"
#include "../headers/get_next_line.h"

int	exec_ope(char *line, t_list **a, t_list **b)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

int	get_operations(t_list **a, t_list **b)
{
	char	*line;
	char	*file;

	file = NULL;
	while (get_next_line(0, &line, &file))
	{
		if (!(exec_ope(line, a, b)))
		{
			lst_clear(a);
			lst_clear(b);
			free(line);
			free(file);
			write(STDERR_FILENO, "Error\n", 6);
			return (0);
		}
		free(line);
	}
	return (1);
}

int	is_sort(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	if (ac <= 1)
		return (0);
	if (!(get_list_a(&a, ac, av)))
		return (0);
	if (!(get_operations(&a, &b)))
		return (0);
	if (is_sort(&a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}
