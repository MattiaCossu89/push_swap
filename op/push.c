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
	if (*fromlst == (*fromlst)->next)
		(*fromlst) = 0;
	else
	{
		(*fromlst) = (*fromlst)->next;
		(*fromlst)->prev = temp->prev;
		temp->prev->next = (*fromlst);
	}
	ft_ilst_addfront(tolst, temp);
}

void	pa(t_all *all)
{
	if (!all->b.ss)
		return ;
	push(&all->b.ss, &all->a.ss);
	all->b.len--;
	all->a.len++;
	if (all->print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_all *all)
{
	if (!all->a.ss)
		return ;
	push(&all->a.ss, &all->b.ss);
	all->b.len++;
	all->a.len--;
	if (all->print)
		ft_putstr_fd("pb\n", 1);
}
