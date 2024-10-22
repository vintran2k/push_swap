/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:48:51 by vintran           #+#    #+#             */
/*   Updated: 2021/06/10 18:57:52 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	*init_var(t_list **list, int *size, int *i)
{
	int	*tab;

	*size = list_len(list);
	tab = list_to_tab(list);
	*i = 0;
	return (tab);
}

int	get_pos(t_list **b, int value)
{
	int		size;
	int		*tab;
	int		i;

	tab = init_var(b, &size, &i);
	while (i < size - 1)
	{
		if (i == 0)
		{
			if (value < tab[size - 1] && value > tab[i])
			{
				free(tab);
				return (i);
			}
		}
		if (value < tab[i] && value > tab[i + 1])
		{
			free(tab);
			return (i + 1);
		}
		i++;
	}
	free(tab);
	return (-1);
}

int	get_rpos(t_list **a, int value)
{
	int		size;
	int		*tab;
	int		i;

	tab = init_var(a, &size, &i);
	while (i < size - 1)
	{
		if (i == 0)
		{
			if (value > tab[size - 1] && value < tab[i])
			{
				free(tab);
				return (i);
			}
		}
		if (value > tab[i] && value < tab[i + 1])
		{
			free(tab);
			return (i + 1);
		}
		i++;
	}
	free(tab);
	return (-1);
}

int	get_bigger_pos(t_list **lst)
{
	t_list	*tmp;
	int		i;
	int		bigger;
	int		pos;

	tmp = (*lst)->next;
	i = 1;
	bigger = (*lst)->data;
	pos = 0;
	while (tmp)
	{
		if (tmp->data > bigger)
		{
			bigger = tmp->data;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	get_lower_pos(t_list **lst)
{
	t_list	*tmp;
	int		i;
	int		lower;
	int		pos;

	tmp = (*lst)->next;
	i = 1;
	lower = (*lst)->data;
	pos = 0;
	while (tmp)
	{
		if (tmp->data < lower)
		{
			lower = tmp->data;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}
