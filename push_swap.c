#include "push_swap.h"

int		main(int ac, char **av)
{
	t_all	all;
	t_ilst	*it;
	int		i;

	if (ac == 1)
		exit(1);
	ft_bzero(&all, sizeof(t_all));
	insert_input(&all, ac, av);
	fill_stack_a(&all);
	sort_input(&all);
	compute_sorting(&all);
	// printf("-----------\n");
	// print_stack(all.a.ss);
	// printf("-----------\n");
	return (0);
}
