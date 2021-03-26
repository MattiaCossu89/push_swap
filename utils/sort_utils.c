/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:25:22 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 17:25:22 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ilst	**ft_realloc_arr(t_ilst **in, size_t n)
{
	t_ilst	**new;
	int		i;

	i = -1;
	if (!(new = ft_calloc(n + 1, sizeof(t_ilst *))))
		return (0);
	while (in[++i])
		new[i] = in[i];
	return (new);
}

void	clear_lists(t_all *all)
{
	t_lst	*it;

	it = all->m.subs;
	while (it->next && (all->m.subs = it->next))
	{
		free(it->cont);
		free(it);
		it = all->m.subs;
	}
	all->m.active = all->m.subs->cont;
	free(all->m.subs);
	all->m.len = all->m.lens[all->m.len - 1];
	free(all->m.lens);
}

void	restore_stack(t_all *all)
{
	t_ilst	*f;
	t_ilst	*b;

	f = all->a.ss;
	b = all->a.ss;
	while (f->ri != 0 && b->ri != 0)
	{
		f = f->next;
		b = b->prev;
	}
	if (f->ri == 0)
		while (all->a.ss->ri != 0)
			ra(all);
	else
		while (all->a.ss->ri != 0)
			rra(all);
}
