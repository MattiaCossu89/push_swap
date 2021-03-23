#include "push_swap.h"

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
		count = min(ABS(new_sol.ar), ABS(new_sol.br));
	if (SIGN(sol->ar) == SIGN(sol->br) || sol->equ)
		counts = min(ABS(sol->ar), ABS(sol->br));
	if ((ABS(new_sol.ar) + ABS(new_sol.br) - count) <
		(ABS(sol->ar) + ABS(sol->br) - counts))
	{
		sol->ar = new_sol.ar;
		sol->br = new_sol.br;
		sol->equ = new_sol.equ;
	}
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

	sol.ar = all->len;
	sol.br = all->len;
	while (all->b.ss)
	{
		find_best_candidate(all, &sol);
		apply_sort(all, sol);
	}
	restore_stack(all);
}
