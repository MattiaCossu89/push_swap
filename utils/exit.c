#include "struct_def.h"

void	exit_all(t_all *all)
{
	free(all->in);
	free(all->insort);
	ft_ilst_clear(&all->a.ss);
	ft_ilst_clear(&all->b.ss);
	exit(1);
}

void	exit_error(t_all *all)
{
	ft_putstr_fd("Error\n", 2);
	exit_all(all);
}
