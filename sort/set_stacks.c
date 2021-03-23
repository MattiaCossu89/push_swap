#include "push_swap.h"

void	push_back_fnl(t_all *all)
{
	rrb(all);
	pa(all);
	if (all->b.ss->prev->ri == all->len - 1)
	{
		rrb(all);
		pa(all);
	}
}

void	push_back_lnf(t_all *all)
{
	rrb(all);
	if (all->b.ss->prev->ri == 0)
	{
		rrb(all);
		pa(all);
	}
	pa(all);
}

void	push_back_first(t_all * all)
{
	if (!all->b.ss)
		return ;
	if (all->b.ss->ri == 0)
		pa(all);
	if (all->b.ss && all->b.ss->ri == all->len - 1)
		pa(all);
	if (all->b.ss && all->b.ss->ri == 0)
		pa(all);
}

void	push_back_minnmax(t_all *all)
{
	push_back_first(all);
	if (!all->b.ss)
		return ;
	if (all->a.ss->ri != 0 && all->a.ss->ri != all->len - 1)
	{
		if (all->b.ss->prev->ri == 0)
			push_back_fnl(all);
		else if (all->b.ss->prev->ri == all->len - 1)
			push_back_lnf(all);
	}
	else if (all->a.ss->ri == 0 && all->b.ss->prev->ri == all->len - 1)
	{
			rrb(all);
			pa(all);
	}
	else if (all->a.ss->ri == all->len - 1 && all->b.ss->prev->ri == 0)
	{
			ra(all);
			rrb(all);
			pa(all);
	}
}

void	push_nbrs_between(t_all *all, int i)
{
	t_ilst *tmp;

	tmp = all->a.ss;
	if (!all->b.ss)
		return ;
	while (all->b.ss && all->b.ss->ri > all->a.ss->prev->ri && (i == all->m.len ||
			all->b.ss->ri < all->m.active[i]->ri))
	{
		if (all->a.ss != tmp && all->a.ss->ri < all->b.ss->ri)
			ra(all);
		pa(all);
	}
	while (all->a.ss != tmp)
		ra(all);
}

void	compute_ra(t_all *all, int i)
{

	if (all->m.len > 1)
		ra(all);
	push_nbrs_between(all, i);
}

void	set_stacks(t_all *all)
{
	int		i;

	i = 0;
	while (42)
	{
		if (i < all->m.len && all->a.ss == all->m.active[i] && ++i)
			compute_ra(all, i);
		else if ((all->m.active[0]->ri != 0 && all->a.ss->ri == 0) ||
		(all->a.ss->ri == all->len - 1 && all->m.active[all->m.len - 1]->ri
		!= all->len - 1))
		{
			pb(all);
			if (all->b.len > 1 && i < all->m.len && all->a.ss->ri == all->m.active[i]->ri && ++i)
			{
				rr(all);
				push_nbrs_between(all, i);
			}
			else if (all->b.len > 1 && all->a.ss->ri != all->m.active[0]->ri)
				rb(all);
		}
		else if ((i >= all->m.len && (all->a.ss == all->m.active[0])))
			break ;
		else
			pb(all);
	}
	push_back_minnmax(all);
}
