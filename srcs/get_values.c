/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:49:18 by vintran           #+#    #+#             */
/*   Updated: 2021/06/10 17:07:20 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	mov_sup(int movs, t_list **b, t_algo *algo)
{
	int	common;
	int	pos;

	pos = get_pos(b, algo->h_first);
	if (pos == -1)
		pos = get_bigger_pos(b);
	if (pos > algo->b_len / 2)
		pos = pos - algo->b_len;
	if (pos > 0)
	{
		common = min(movs, pos);
		algo->rr = common;
		if (pos == common)
			algo->ra = movs - common;
		else
			algo->rb = pos - common;
	}
	else
	{
		algo->ra = movs;
		algo->rrb = -pos;
	}
}

void	mov_inf(int movs, t_list **b, t_algo *algo)
{
	int	common;
	int	pos;

	movs = -movs;
	pos = get_pos(b, algo->h_second);
	if (pos == -1)
		pos = get_bigger_pos(b);
	if (pos > algo->b_len / 2)
		pos = pos - algo->b_len;
	if (pos < 0)
	{
		pos = -pos;
		common = min(movs, pos);
		algo->rrr = common;
		if (pos == common)
			algo->rra = movs - common;
		else
			algo->rrb = pos - common;
	}
	else
	{
		algo->rb = pos;
		algo->rra = movs;
	}
}

void	get_values(t_list **b, t_algo *algo)
{
	int	movs;

	movs = get_movs(algo);
	if (movs >= 0)
		mov_sup(movs, b, algo);
	else if (movs < 0)
		mov_inf(movs, b, algo);
}
