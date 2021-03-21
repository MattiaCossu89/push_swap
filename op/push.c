/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:54:22 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/17 19:02:14 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_ilst **fromlst, t_ilst **tolst)
{
	t_ilst *temp;

	if (!fromlst || !*fromlst)
		return ;
	temp = *fromlst;
	(*fromlst) = (*fromlst)->next;
	temp->next = 0;
	if (*fromlst)
		(*fromlst)->prev = temp->prev;
	ft_ilst_addfront(tolst, temp);
}

void	pa(t_all *all)
{
	char	check;

	check = 0;
	if (!all->b.ss)
		return ;
	if (!all->a.ss)
		check = 1;
	push(&all->b.ss, &all->a.ss);
	if (check)
		all->a.se = all->a.ss;
	all->b.len--;
	all->a.len++;
	if (all->print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_all *all)
{
	char	check;

	check = 0;
	if (!all->a.ss)
		return ;
	if (!all->b.ss)
		check = 1;
	push(&all->a.ss, &all->b.ss);
	if (check)
		all->b.se = all->b.ss;
	all->b.len++;
	all->a.len--;
	if (all->print)
		ft_putstr_fd("pb\n", 1);
}
