/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:25:16 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 17:25:17 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_input(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->len)
	{
		ft_putnbr_fd(all->insort[i]->ri, 1);
		ft_putstr_fd(" -> ", 1);
		ft_putnbr_fd(all->in[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	print_stat(t_all *all)
{
	ft_printf("sa:\t\t%d\n", all->op.sa);
	ft_printf("sb:\t\t%d\n", all->op.sb);
	ft_printf("ss:\t\t%d\n", all->op.ss);
	ft_printf("pa:\t\t%d\n", all->op.pa);
	ft_printf("pb:\t\t%d\n", all->op.pb);
	ft_printf("ra:\t\t%d\n", all->op.ra);
	ft_printf("rb:\t\t%d\n", all->op.rb);
	ft_printf("rr:\t\t%d\n", all->op.rr);
	ft_printf("rra:\t\t%d\n", all->op.rra);
	ft_printf("rrb:\t\t%d\n", all->op.rrb);
	ft_printf("rrr:\t\t%d\n", all->op.rrr);
	ft_printf("total ops:\t%d\n", all->op.tot);
}

void	mnm_a(t_all *all, t_ilst **min, t_ilst **max)
{
	t_ilst *it;
	t_ilst *f;

	f = all->a.ss;
	it = all->a.ss->next;
	*min = f;
	*max = f;
	while (it != f)
	{
		if (it->ri < (*min)->ri)
			*min = it;
		if (it->ri > (*max)->ri)
			*max = it;
		it = it->next;
	}
}

int		pos_a(t_all *all, t_ilst *tof)
{
	t_ilst	*f;
	t_ilst	*it;
	int		i;

	i = 0;
	f = all->a.ss->prev;
	it = all->a.ss;
	while (it != f)
	{
		if (it == tof)
			return (i);
		i++;
		it = it->next;
	}
	if (it != tof)
		return (-1);
	return (i);
}

void	print_stacks(t_all *all)
{
	print_head(all);
	print_body(all);
	print_line(all);
}
