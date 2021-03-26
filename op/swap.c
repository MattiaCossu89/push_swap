/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:48:25 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 16:42:38 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_ilst **stack)
{
	t_ilst	*t1;
	t_ilst	*t2;

	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	t1 = *stack;
	t2 = (*stack)->next;
	if (t1 == t2->next)
	{
		t2->prev = t1;
		t2->next = t1;
		t1->next = t2;
		t1->prev = t2;
	}
	else
	{
		t2->prev = t1->prev;
		t1->next = t2->next;
		t2->next = t1;
		t2->prev->next = t2;
		t1->prev = t2;
		t1->next->prev = t1;
	}
	*stack = t2;
	// temp = stack->n;
	// stack->n = stack->next->n;
	// stack->next->n = temp;
	// temp = stack->ri;
	// stack->ri = stack->next->ri;
	// stack->next->ri = temp;
}

void	sa(t_all *all)
{
	swap(&all->a.ss);
	if (all->print)
	{
		if (all->file)
			ft_putstr_fd("sa\n", all->file);
		else
			ft_putstr_fd("sa\n", 1);
	}
	avait_n(all);
	all->op.tot++;
	all->op.sa++;
}

void	sb(t_all *all)
{
	swap(&all->b.ss);
	if (all->print)
	{
		if (all->file)
			ft_putstr_fd("sb\n", all->file);
		else
			ft_putstr_fd("sb\n", 1);
	}
	all->op.tot++;
	all->op.sb++;
}

void	ss(t_all *all)
{
	sa(all);
	sb(all);
	if (all->print)
	{
		if (all->file)
			ft_putstr_fd("ss\n", all->file);
		else
			ft_putstr_fd("ss\n", 1);
	}
	avait_n(all);
	all->op.tot++;
	all->op.ss++;
}
