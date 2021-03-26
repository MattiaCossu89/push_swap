/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littlesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:24:21 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 17:24:22 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushb(t_all *all, int count)
{
	while (count > 0)
	{
		ra(all);
		count--;
	}
	while (count < 0)
	{
		rra(all);
		count++;
	}
	pb(all);
}

void	sort_three(t_all *all)
{
	int		max;
	int		min;

	find_mnm(all->a.ss, &min, &max);
	if ((all->a.ss->ri == max && all->a.ss->next->ri != min) ||
		(all->a.ss->next->next->ri == max && all->a.ss->ri != min) ||
		(all->a.ss->next->ri == max && all->a.ss->next->next->ri != min))
		sa(all);
	if (all->a.ss->ri != min && all->a.ss->next->ri == min)
		ra(all);
	else if (all->a.ss->ri != min && all->a.ss->next->ri != min)
		rra(all);
}

void	push_fnl(t_all *all)
{
	int		cf;
	int		cl;

	cf = find_pos_f(all);
	cl = find_pos_l(all);
	if (ABS(cf) > ABS(cl))
	{
		pushb(all, cl);
		cf = find_pos_f(all);
		pushb(all, cf);
	}
	else
	{
		pushb(all, cf);
		cl = find_pos_l(all);
		pushb(all, cl);
	}
}

void	push_back(t_all *all)
{
	if (all->b.ss->ri == all->len - 1)
	{
		pa(all);
		ra(all);
		pa(all);
	}
	else
	{
		pa(all);
		pa(all);
		ra(all);
	}
}

void	little_sort(t_all *all)
{
	push_fnl(all);
	sort_three(all);
	push_back(all);
}
