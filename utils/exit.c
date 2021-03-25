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

void	free_avv(char  ***avv)
{
	int	i;
	int	j;

	i = 0;
	while (avv[i])
	{
		j = 0;
		while (avv[i][j])
		{
			printf("%s\n", avv[i][j]);
			free(avv[i][j]);
			j++;
		}
		free(avv[i]);
		i++;
	}
	free(avv);
}

void	exit_error_avv(t_all *all, char ***av)
{
	free_avv(av);
	exit_error(all);
}
