/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:07:01 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 17:28:49 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_sorted(t_all *all, int i)
{
	const char	*color;
	t_ilst		*min;
	t_ilst		*max;

	color = "";
	mnm_a(all, &min, &max);
	if (all->fc)
	{
		if ((all->insort[i]->ri > all->insort[i]->prev->ri ||
			(all->insort[i]->prev->ri == max->ri && all->insort[i] == min)) &&
			(all->insort[i]->ri < all->insort[i]->next->ri ||
			(all->insort[i]->next->ri == min->ri && all->insort[i] == max)))
			color = YEL;
		else
			color = RED;
		if (all->insort[i]->ri == pos_a(all, all->insort[i]))
			color = GRN;
		ft_printf(" %s%*d%s |\n", color,
			all->maxnl, all->insort[i]->n, "\033[0m");
	}
	else
		ft_printf(" %*d |\n",
			all->maxnl, all->insort[i]->n);
}

void	print_body(t_all *all)
{
	int		i;
	t_ilst	*a;
	t_ilst	*b;

	i = -1;
	a = all->a.ss;
	b = all->b.ss;
	while (++i < all->len)
	{
		if (i < all->a.len)
			ft_printf("\t| %*d |",
			all->maxnl, a->n);
		else
			ft_printf("\t| %*s |",
			all->maxnl, "");
		if (i < all->b.len)
			ft_printf(" %*d |",
			all->maxnl, b->n);
		else
			ft_printf(" %*s |",
			all->maxnl, "");
		print_sorted(all, i);
		a = a ? a->next : 0;
		b = b ? b->next : 0;
	}
}

void	print_stack(t_ilst *lst)
{
	t_ilst *last;

	if (!lst)
		return ;
	last = lst->prev;
	while (lst != last)
	{
		ft_putnbr_fd(lst->n, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
	}
	ft_putnbr_fd(lst->n, 1);
	ft_putchar_fd('\n', 1);
}

void	print_line(t_all *all)
{
	int	i;

	i = 0;
	ft_putstr_fd("\t+", 1);
	while (i++ < all->maxnl + 2)
		ft_putchar_fd('-', 1);
	ft_putchar_fd('+', 1);
	i = 0;
	while (i++ < all->maxnl + 2)
		ft_putchar_fd('-', 1);
	ft_putstr_fd("+", 1);
	i = 0;
	while (i++ < all->maxnl + 2)
		ft_putchar_fd('-', 1);
	ft_putstr_fd("+\n", 1);
}

void	print_head(t_all *all)
{
	print_line(all);
	ft_printf("\t| %*s%*s | %*s%*s | %*s%*s |\n",
	all->maxnl / 2 + 1, "a", all->maxnl / 2, "",
	all->maxnl / 2 + 1, "b", all->maxnl / 2, "",
	all->maxnl / 2 + 1, "r", all->maxnl / 2, "");
	print_line(all);
}
