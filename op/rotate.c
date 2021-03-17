/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:08:15 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/17 17:53:04 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_stack *stack)
{
	t_ilst *temp;

	if (!stack || stack->len == 1)
		return ;
	temp = stack->ss->next;
	temp->prev = 0;
	stack->se->next = stack->ss;
	stack->ss->prev = stack->se;
	stack->ss = temp;
	stack->se = stack->se->next;
}

void	ra(t_all *all)
{
	rotate(&all->a);
}

void	rb(t_all *all)
{
	rotate(&all->b);
}

void	rr(t_all *all)
{
	rotate(&all->a);
	rotate(&all->b);
}
