#include "push_swap.h"

void	compute_sorting(t_all *all)
{
	find_max_sub(all);
	clear_lists(all);
	all->print = 1;
	if (all->len < 4 || all->len == all->m.len)
	{
		sort_three(all);
		return ;
	}
	if (all->len > 5)
	{
		set_stacks(all);
		sort(all);
	}
	else
		little_sort(all);
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac == 1)
		exit(1);
	ft_bzero(&all, sizeof(t_all));
	insert_input(&all, ac, av);
	fill_stack_a(&all);
	sort_input(&all);
	compute_sorting(&all);
	exit_all(&all);
	return (0);
}
