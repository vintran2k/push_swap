/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:46:10 by vintran           #+#    #+#             */
/*   Updated: 2021/06/10 16:47:31 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	lst_clear(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	remove_top(t_list **lst)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	free(*lst);
	if (tmp != NULL)
		tmp->prev = NULL;
	*lst = tmp;
}

t_list	*init_list(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	push_back(t_list **lst, int data)
{
	t_list	*tmp;
	t_list	*new;

	new = init_list(data);
	if (!new)
		return ;
	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	push_front(t_list **lst, int data)
{
	t_list	*new;

	new = init_list(data);
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}
