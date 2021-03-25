/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:08:15 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/25 15:52:33 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_stack *stack)
{
	if (!stack || stack->len == 1)
		return ;
	stack->ss = stack->ss->next;
}

void	ra(t_all *all)
{
	rotate(&all->a);
	if (all->print)
	{
		if (all->file)
			ft_putstr_fd("ra\n", all->file);
		else
			ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_all *all)
{
	rotate(&all->b);
	if (all->print)
	{
		if (all->file)
			ft_putstr_fd("rb\n", all->file);
		else
			ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_all *all)
{
	rotate(&all->a);
	rotate(&all->b);
	if (all->print)
	{
		if (all->file)
			ft_putstr_fd("rr\n", all->file);
		else
			ft_putstr_fd("rr\n", 1);
	}
}
