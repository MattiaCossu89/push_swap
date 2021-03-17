/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:54:22 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/17 17:35:27 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_ilst **fromlst, t_ilst **tolst)
{
	t_ilst *temp;

	if (!fromlst || !*fromlst)
		return ;
	temp = *fromlst;
	temp->next = 0;
	(*fromlst) = (*fromlst)->next;
	if (*fromlst)
		(*fromlst)->prev = 0;
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
}
