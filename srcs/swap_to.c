/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:57:00 by vintran           #+#    #+#             */
/*   Updated: 2021/06/10 17:09:48 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	swap_to_a(t_list **a, t_list **b, t_algo *algo)
{
	int	bp;
	int	b_len;
	int	movs;
	int	ret;

	bp = get_bigger_pos(b);
	b_len = list_len(b);
	movs = bp;
	ret = 0;
	if (bp > b_len / 2)
		movs = b_len - bp;
	while (movs-- > 0)
	{
		if (bp <= b_len / 2)
			rb(b, algo->display);
		else
			rrb(b, algo->display);
		ret++;
	}
	while (*b != NULL)
	{
		pa(a, b, algo->display);
		ret++;
	}
	return (ret);
}
