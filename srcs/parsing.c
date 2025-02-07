/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:53:13 by vintran           #+#    #+#             */
/*   Updated: 2021/06/10 17:09:03 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_sorted(t_list **a)
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

int	parse_arg(char *str, t_list **a)
{
	char	**strs;
	int		i;
	int		flag;

	flag = 1;
	i = 0;
	if (is_space(str))
	{
		strs = ft_split(str, ' ');
		while (strs[i])
		{
			if (!check_arg(strs[i]) && !check_duplicate(a, ft_atoi(strs[i])))
				flag = 0;
			push_back(a, ft_atoi(strs[i]));
			free(strs[i]);
			i++;
		}
		free(strs);
	}
	else if (check_arg(str) && check_duplicate(a, ft_atoi(str)))
		push_back(a, ft_atoi(str));
	else
		flag = 0;
	return (flag);
}

int	parsing_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (0);
}

int	parsing(int ac, char **av, t_list **a, t_list **b)
{
	int		i;
	t_size	mysize;

	i = 1;
	while (i < ac)
	{
		if (!(parse_arg(av[i], a)))
			return (parsing_error());
		i++;
	}
	mysize.size = list_len(a);
	if (is_sorted(a))
		return (1);
	if (mysize.size <= 2)
		sort_onetwo(a);
	else if (mysize.size == 3)
		sort_three(a);
	else if (mysize.size <= 5)
		sort_five(a, b);
	else
	{
		mysize.chunksize = check_all(a, b, list_len(a));
		algo(a, b, &mysize, SHOW);
	}
	return (1);
}
