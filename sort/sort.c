#include "push_swap.h"

int		find_pos_a(t_all *all, t_ilst *tof)
{
	int		cr;
	int		crr;
	t_ilst	*r;
	t_ilst	*rr;

	cr = 0;
	crr = 0;
	r = all->a.ss;
	rr = all->a.ss;
	while (tof->ri > r->ri)
	{
		cr++;
		r = r->next;
	}
	while (tof->ri < rr->prev->ri)
	{
		crr--;
		rr = rr->prev;
	}
	if (ABS(cr) < ABS(crr))
		return (crr);
	return (cr);
}

int		max(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	get_best_sol(t_all *all, t_sol *sol, t_ilst *tof, int i)
{
	t_sol	new_sol;
	int		count;
	int		counts;

	new_sol.br = i;
	new_sol.ar = find_pos_a(all, tof);
	count = 0;
	counts = 0;
	if (SIGN(new_sol.ar) == SIGN(new_sol.br))
		count = max(ABS(new_sol.ar), ABS(new_sol.br));
	if (SIGN(sol->ar) == SIGN(sol->br))
		counts = max(ABS(new_sol.ar), ABS(new_sol.br));
	if ((ABS(new_sol.ar) + ABS(new_sol.br) - count) < (ABS(sol->ar) + ABS(sol->br) - counts))
	{
		sol->ar = new_sol.ar;
		sol->br = new_sol.br;
	}
}

t_sol	find_best_candidate(t_all *all)
{
	int		i;
	t_ilst	*first;
	t_sol	sol;
	t_ilst	*r;
	t_ilst	*rr;

	i = 0;
	first = all->b.ss;
	r = all->b.ss->next;
	rr = all->b.ss->prev;
	sol.ar = find_pos_a(all, all->b.ss);
	sol.br = 0;
	while (r != first)
	{
		i++;
		get_best_sol(all, &sol, r, i);
		get_best_sol(all, &sol, rr, -i);
		r = r->next;
		rr = rr->prev;
	}
	return (sol);
}

void	apply_rrr(t_all *all, t_sol sol)
{
	while (sol.ar < 0 && sol.br < 0)
	{
		rrr(all);
		sol.ar++;
		sol.br++;
	}
	while (sol.ar < 0)
	{
		rra(all);
		sol.ar++;
	}
	while (sol.ar > 0)
	{
		ra(all);
		sol.ar--;
	}
	while (sol.br < 0)
	{
		rrb(all);
		sol.br++;
	}
	pa(all);
}

void	apply_rr(t_all *all, t_sol sol)
{
	while (sol.ar > 0 && sol.br > 0)
	{
		rr(all);
		sol.ar--;
		sol.br--;
	}
	while (sol.br > 0)
	{
		rb(all);
		sol.br--;
	}
	while (sol.ar > 0)
	{
		ra(all);
		sol.ar--;
	}
	while (sol.ar < 0)
	{
		rra(all);
		sol.ar++;
	}
	pa(all);
}

void	apply_sort(t_all *all, t_sol sol)
{
	if (SIGN(sol.br) < 0)
		apply_rrr(all, sol);
	else
		apply_rr(all, sol);
}

void	sort(t_all *all)
{
	t_sol	sol;
	t_ilst	*f;
	t_ilst	*b;

	while (all->b.ss)
	{
		sol = find_best_candidate(all);
		apply_sort(all, sol);
		// sleep(10);
	}
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
	// print_stack(all->a.ss);
	// printf("*************\n");
	// print_stack(all->b.ss);
}
