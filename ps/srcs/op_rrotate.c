/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:51:42 by vintran           #+#    #+#             */
/*   Updated: 2021/05/31 17:51:50 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rra(t_list **a, int option)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *a;
	(*a)->prev = tmp;
	*a = tmp;
	if (option == SHOW)
		printf("rra\n");
}

void	rrb(t_list **b, int option)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *b;
	(*b)->prev = tmp;
	*b = tmp;
	if (option == SHOW)
		printf("rrb\n");
}

void	rrr(t_list **a, t_list **b, int option)
{
	rra(a, HIDE);
	rrb(b, HIDE);
	if (option == SHOW)
		printf("rrr\n");
}
