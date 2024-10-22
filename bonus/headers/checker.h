/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:05:31 by vintran           #+#    #+#             */
/*   Updated: 2021/06/09 16:45:34 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../headers/push_swap.h"

int		get_list_a(t_list **a, int ac, char **av);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);
void	lst_clear(t_list **lst);

#endif
