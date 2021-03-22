#include "glob_func.h"

void	insert_input(t_all *all, int ac, char **av)
{
	int	i;

	i = 1;
	if (!(all->in = ft_calloc(ac, sizeof(int))))
		exit_error(all);
	while (i < ac)
	{
		if (!ft_isnumber(av[i]))
			exit_error(all);
		all->in[i - 1] = ft_atoi(av[i]);
		if (ft_strlen(av[i]) != (size_t)ft_intlen(all->in[i - 1]))
			exit_error(all);
		i++;
	}
	all->len = ac - 1;
}

void	init_input(t_all *all)
{
	int		i;
	t_ilst	*it;

	i = all->len;
	if (!(all->insort = ft_calloc(all->len, sizeof(t_ilst *))))
		exit_error(all);
	i = -1;
	it = all->a.ss;
	while (++i < all->len)
	{
		all->insort[i] = it;
		it->ri = i;
		it = it->next;
	}
}

void	sort_input(t_all *all)
{
	int		i;
	int		j;
	t_ilst	*temp;

	i = 0;
	init_input(all);
	while (i < all->len)
	{
		j = i;
		while (++j < all->len)
		{
			if (all->insort[i]->n == all->insort[j]->n)
				exit_error(all);
			if (all->insort[i]->n > all->insort[j]->n)
			{
				all->insort[i]->ri = j;
				all->insort[j]->ri = i;
				temp = all->insort[i];
				all->insort[i] = all->insort[j];
				all->insort[j] = temp;
			}
		}
		i++;
	}
}

void	fill_stack_a(t_all *all)
{
	t_ilst	*new;
	int		i;

	i = 0;
	while (i < all->len)
	{
		if (!(new = ft_ilst_new(all->in[i])))
			exit_error(all);
		if (!all->a.ss)
			ft_ilst_addfront(&all->a.ss, new);
		else
			ft_ilst_addback(&all->a.ss, new);
		i++;
	}
	all->a.len = all->len;
}
