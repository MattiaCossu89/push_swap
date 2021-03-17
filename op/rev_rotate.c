/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:53:23 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/17 17:56:27 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_rotate(t_stack *stack)
{
	t_ilst *temp;

	if (!stack || stack->len == 1)
		return ;
	temp = stack->se->prev;
	temp->next = 0;
	stack->ss->prev = stack->se;
	stack->se->next = stack->ss;
	stack->ss = stack->ss->prev;
	stack->se = temp;
}

void	rra(t_all *all)
{
	rev_rotate(&all->a);
}

void	rrb(t_all *all)
{
	rev_rotate(&all->b);
}

void	rrr(t_all *all)
{
	rev_rotate(&all->a);
	rev_rotate(&all->b);
}
