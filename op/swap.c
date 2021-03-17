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
}

void	sb(t_all *all)
{
	swap(all->b.ss);
}

void	ss(t_all *all)
{
	sa(all);
	sb(all);
}
