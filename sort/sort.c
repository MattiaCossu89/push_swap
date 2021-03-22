#include "push_swap.h"

void	find_pos_a(t_all *all, t_ilst *tof, t_sol *sol)
{
	int		cr;
	int		crr;
	t_ilst	*r;
	t_ilst	*rr;

	cr = 0;
	crr = 0;
	r = all->a.ss;
	rr = all->a.ss;
	while (!(tof->ri > r->prev->ri && tof->ri < r->ri))
	{
		cr++;
		r = r->next;
	}
	while (!(tof->ri > rr->prev->ri && tof->ri < rr->ri))
	{
		crr--;
		rr = rr->prev;
	}
	// if (ABS(cr) == ABS(crr))
	// 	sol->equ = 1;
	if (ABS(cr) > ABS(crr))
		sol->ar = crr;
	else
		sol->ar = cr;
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
	new_sol.equ = 0;
	find_pos_a(all, tof, &new_sol);
	count = 0;
	counts = 0;
	if (SIGN(new_sol.ar) == SIGN(new_sol.br) || new_sol.equ)
		count = max(ABS(new_sol.ar), ABS(new_sol.br));
	if (SIGN(sol->ar) == SIGN(sol->br) || sol->equ)
		counts = max(ABS(new_sol.ar), ABS(new_sol.br));
	if ((ABS(new_sol.ar) + ABS(new_sol.br) - count) < (ABS(sol->ar) + ABS(sol->br) - counts))
	{
		sol->ar = new_sol.ar;
		sol->br = new_sol.br;
		sol->equ = new_sol.equ;
	}
}

t_sol	find_best_candidate(t_all *all, t_sol *sol)
{
	int		i;
	t_ilst	*first;
	t_ilst	*r;
	t_ilst	*rr;

	i = 0;
	first = all->b.ss;
	r = all->b.ss->next;
	rr = all->b.ss->prev;
	find_pos_a(all, all->b.ss, sol);
	sol->br = 0;
	while (r != first)
	{
		i++;
		get_best_sol(all, sol, r, i);
		get_best_sol(all, sol, rr, -i);
		r = r->next;
		rr = rr->prev;
	}
	return (*sol);
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
	if (sol.equ)
	{
		if(SIGN(sol.br) != SIGN(sol.ar))
		{
			sol.ar = -sol.ar;
		}
	}
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
		find_best_candidate(all, &sol);
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
