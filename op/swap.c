/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:48:25 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/17 15:54:07 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_ilst *stack)
{
	int		temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->n;
	stack->n = stack->next->n;
	stack->next->n = temp;
	temp = stack->ri;
	stack->ri = stack->next->ri;
	stack->next->ri = temp;
}

void	sa(t_all *all)
{
	swap(all->a.ss);
	if (all->print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_all *all)
{
	swap(all->b.ss);
	if (all->print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_all *all)
{
	sa(all);
	sb(all);
	if (all->print)
		ft_putstr_fd("ss\n", 1);
}
