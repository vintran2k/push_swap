/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:56:25 by vintran           #+#    #+#             */
/*   Updated: 2021/05/31 17:56:40 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_onetwo(t_list **a)
{
	if ((*a)->next)
	{
		if ((*a)->data > (*a)->next->data)
			sa(a, SHOW);
	}
}

void	sort_three(t_list **a)
{
	int		num[3];

	fill_tab(a, num, 3);
	if ((num[0] > num[1]) && (num[0] < num[2]) && (num[1] < num[2]))
		sa(a, SHOW);
	else if ((num[0] > num[1]) && (num[1] > num[2]))
	{
		sa(a, SHOW);
		rra(a, SHOW);
	}
	else if ((num[0] > num[1]) && (num[0] > num[1]) && (num[1] < num[2]))
		ra(a, SHOW);
	else if ((num[0] < num[1]) && (num[0] < num[2]) && (num[1] > num[2]))
	{
		sa(a, SHOW);
		ra(a, SHOW);
	}
	else if ((num[0] < num[1]) && (num[0] > num[2]) && (num[1] > num[2]))
		rra(a, SHOW);
}
