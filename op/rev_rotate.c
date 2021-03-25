/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:53:23 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/25 15:52:13 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_rotate(t_stack *stack)
{
	if (!stack || stack->len == 1)
		return ;
	stack->ss = stack->ss->prev;
}

void	rra(t_all *all)
{
	rev_rotate(&all->a);
	if (all->print)
	{
		if (all->file)
			ft_putstr_fd("rra\n", all->file);
		else
			ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_all *all)
{
	rev_rotate(&all->b);
	if (all->print)
	{
		if (all->file)
			ft_putstr_fd("rrb\n", all->file);
		else
			ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_all *all)
{
	rev_rotate(&all->a);
	rev_rotate(&all->b);
	if (all->print)
	{
		if (all->file)
			ft_putstr_fd("rrr\n", all->file);
		else
			ft_putstr_fd("rrr\n", 1);
	}
}
