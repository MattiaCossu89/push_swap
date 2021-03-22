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

void	print_max_sub(t_all *all)
{
	t_lst	*it;
	int		i;

	i = 0;
	while (i < all->m.len)
	{
		ft_putnbr_fd(all->m.active[i]->n, 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	print_all(t_all *all)
{
	int i;

	i = 0;
	while (i < all->m.len)
		printf("%d ", all->m.lens[i++]);
		printf("\n");
}

char	find_case(t_ilst *it, t_all *all)
{
	t_lst	*lit;
	t_lst	*prev;
	int		i;

	i = -1;
	lit = all->m.subs;
	all->m.active = lit->cont;
	if (all->m.active[all->m.lens[0] - 1]->ri > it->ri)
		return (1);
	while (++i < all->m.len && all->m.active[all->m.lens[i] - 1]->ri < it->ri
			&& (prev = lit))
	{
		lit = lit->next;
		if (lit)
			all->m.active = lit->cont;
	}
	all->m.found = prev;
	all->m.active = prev->cont;
	all->m.ifound = i - 1;
	if (i == all->m.len)
		return (2);
	return (3);
}

void	extend(t_all *all, t_ilst *it)
{
	int		i;
	t_lst	*new;

	i = all->m.ifound;
	ft_memmove(&all->m.lens[i + 1], &all->m.lens[i],
				sizeof(int) * (all->m.len - i));
	all->m.len++;
	all->m.lens[i + 1]++;
	if (!(new = ft_lstnew(0)))
		exit_error(all);
	if (!(all->m.active = ft_realloc_arr(all->m.active, all->m.lens[i + 1])))
	{
		free(new);
		exit_error(all);
	}
	all->m.active[all->m.lens[i + 1] - 1] = it;
	new->cont = all->m.active;
	new->next = all->m.found->next;
	all->m.found->next = new;
	all->m.found = all->m.found->next;
	all->m.ifound++;
}

void	discard(t_all *all)
{
	int		i;
	t_lst	*it;

	i = 0;
	it = all->m.subs;
	while (i < all->m.len && all->m.lens[i] <= all->m.lens[all->m.ifound])
	{
		if (it != all->m.found && all->m.lens[i] == all->m.lens[all->m.ifound])
		{
			ft_lstrm_ifnode(&all->m.subs, it, free);
			ft_memmove(&all->m.lens[i], &all->m.lens[i + 1],
						sizeof(int) * (all->m.len - i - 1));
			all->m.len--;
			all->m.lens[all->m.len] = 0;
		}
		i++;
		it = it->next;
	}
}

void	set_lst_active(t_ilst *it, t_all *all)
{
	char	icase;

	icase = find_case(it, all);
	if (icase == 1)
		all->m.active[0] = it;
	else if (icase == 2)
		extend(all, it);
	else if (icase == 3)
	{
		extend(all, it);
		discard(all);
	}
}

void	find_max_sub(t_all *all)
{
	t_ilst		*it;
	t_ilst		*first;

	if (!(all->m.active = ft_calloc(2, sizeof(t_ilst *))))
		exit_error(all);
	it = all->a.ss->next;
	first = all->a.ss;
	all->m.active[0] = all->a.ss;
	if (!(all->m.subs = ft_lstnew(all->m.active)))
		exit_error(all);
	if (!(all->m.lens = ft_calloc(all->len, sizeof(int))))
		exit_error(all);
	all->m.len = 1;
	all->m.lens[0] = 1;
	while (it != first)
	{
		set_lst_active(it, all);
		it = it->next;
	}
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

void	remove_last(t_all *all)
{
	int		i;

	i = -1;
	while (++i < all->rm.len)
	{
		if (all->rm.active[i] == all->m.active[all->m.len - 1])
		{
			ft_memmove(&all->rm.active[i], &all->rm.active[i + 1],
						(all->rm.len - i - 1) * sizeof(t_ilst *));
			all->rm.len--;
			all->rm.active[all->rm.len] = 0;
			return ;
		}
	}
}

void	compute_sorting(t_all *all)
{
	find_max_sub(all);
	clear_lists(all);
	all->print = 1;
	// print_max_sub(all);
	set_stacks(all);
	print_stack(all->a.ss);
	sleep(5);
	sort(all);
	print_stack(all->a.ss);
}
