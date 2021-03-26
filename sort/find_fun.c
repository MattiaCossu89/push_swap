/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:24:12 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 17:24:13 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pos_a(t_all *all, t_ilst *tof, t_sol *sol)
{
	int		cr;
	int		crr;
	t_ilst	*r;
	t_ilst	*rr;

	cr = 0;
	crr = 0;
	r = all->a.ss;
	rr = all->a.ss;
	while (!(tof->ri > r->prev->ri && tof->ri < r->ri))
	{
		cr++;
		r = r->next;
	}
	while (!(tof->ri > rr->prev->ri && tof->ri < rr->ri))
	{
		crr--;
		rr = rr->prev;
	}
	if (ABS(cr) > ABS(crr))
		sol->ar = crr;
	else
		sol->ar = cr;
}

t_sol	find_best_candidate(t_all *all, t_sol *sol)
{
	int		i;
	t_ilst	*first;
	t_ilst	*r;
	t_ilst	*rr;

	i = 0;
	first = all->b.ss;
	r = all->b.ss->next;
	rr = all->b.ss->prev;
	find_pos_a(all, all->b.ss, sol);
	sol->br = 0;
	sol->equ = 0;
	while (r != first)
	{
		i++;
		get_best_sol(all, sol, r, i);
		get_best_sol(all, sol, rr, -i);
		r = r->next;
		rr = rr->prev;
	}
	return (*sol);
}

int		find_pos_f(t_all *all)
{
	t_ilst	*fnl;
	int		cr;
	int		crr;

	fnl = all->a.ss;
	cr = 0;
	crr = 0;
	while (fnl->ri != 0)
	{
		cr++;
		fnl = fnl->next;
	}
	fnl = all->a.ss;
	while (fnl->ri != 0)
	{
		crr--;
		fnl = fnl->prev;
	}
	if (ABS(crr) > ABS(cr))
		return (cr);
	else
		return (crr);
}

int		find_pos_l(t_all *all)
{
	t_ilst	*fnl;
	int		cr;
	int		crr;

	fnl = all->a.ss;
	cr = 0;
	crr = 0;
	while (fnl->ri != all->len - 1)
	{
		cr++;
		fnl = fnl->next;
	}
	fnl = all->a.ss;
	while (fnl->ri != all->len - 1)
	{
		crr--;
		fnl = fnl->prev;
	}
	if (ABS(crr) > ABS(cr))
		return (cr);
	else
		return (crr);
}

void	find_mnm(t_ilst *lst, int *min, int *max)
{
	t_ilst	*f;

	f = lst;
	*max = lst->ri;
	*min = lst->ri;
	lst = lst->next;
	while (lst != f)
	{
		if (lst->ri > *max)
			*max = lst->ri;
		if (lst->ri < *min)
			*min = lst->ri;
		lst = lst->next;
	}
}
