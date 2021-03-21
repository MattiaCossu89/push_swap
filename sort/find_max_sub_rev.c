#include "push_swap.h"

char	find_case_rev(t_ilst *it, t_all *all)
{
	t_lst	*lit;
	t_lst	*prev;
	int		i;

	i = -1;
	lit = all->rm.subs;
	all->rm.active = lit->cont;
	if (all->rm.active[all->rm.lens[0] - 1]->ri < it->ri)
		return (1);
	while (++i < all->rm.len && all->rm.active[all->rm.lens[i] - 1]->ri > it->ri
			&& (prev = lit))
	{
		lit = lit->next;
		if (lit)
			all->rm.active = lit->cont;
	}
	all->rm.found = prev;
	all->rm.active = prev->cont;
	all->rm.ifound = i - 1;
	if (i == all->rm.len)
		return (2);
	return (3);
}

void	extend_rev(t_all *all, t_ilst *it)
{
	int		i;
	t_lst	*new;

	i = all->rm.ifound;
	ft_memmove(&all->rm.lens[i + 1], &all->rm.lens[i],
				sizeof(int) * (all->rm.len - i));
	all->rm.len++;
	all->rm.lens[i + 1]++;
	if (!(new = ft_lstnew(0)))
		exit_error(all);
	if (!(all->rm.active = ft_realloc_arr(all->rm.active, all->rm.lens[i + 1])))
	{
		free(new);
		exit_error(all);
	}
	all->rm.active[all->rm.lens[i + 1] - 1] = it;
	new->cont = all->rm.active;
	new->next = all->rm.found->next;
	all->rm.found->next = new;
	all->rm.found = all->rm.found->next;
	all->rm.ifound++;
}

void	discard_rev(t_all *all)
{
	int		i;
	t_lst	*it;

	i = 0;
	it = all->rm.subs;
	while (i < all->rm.len && all->rm.lens[i] <= all->rm.lens[all->rm.ifound])
	{
		if (it != all->rm.found &&
			all->rm.lens[i] == all->rm.lens[all->rm.ifound])
		{
			ft_lstrm_ifnode(&all->rm.subs, it, free);
			ft_memmove(&all->rm.lens[i], &all->rm.lens[i + 1],
						sizeof(int) * (all->rm.len - i - 1));
			all->rm.len--;
			all->rm.lens[all->rm.len] = 0;
		}
		i++;
		it = it->next;
	}
}

void	set_lst_active_rev(t_ilst *it, t_all *all)
{
	char	icase;

	icase = find_case_rev(it, all);
	if (icase == 1)
		all->rm.active[0] = it;
	else if (icase == 2)
		extend_rev(all, it);
	else if (icase == 3)
	{
		extend_rev(all, it);
		discard_rev(all);
	}
}

void	find_max_sub_rev(t_all *all)
{
	t_ilst		*it;
	t_ilst		*first;

	if (!(all->rm.active = ft_calloc(2, sizeof(t_ilst *))))
		exit_error(all);
	it = all->a.ss->next;
	first = all->a.ss;
	all->rm.active[0] = all->a.ss;
	if (!(all->rm.subs = ft_lstnew(all->rm.active)))
		exit_error(all);
	if (!(all->rm.lens = ft_calloc(all->len, sizeof(int))))
		exit_error(all);
	all->rm.len = 1;
	all->rm.lens[0] = 1;
	while (it != first)
	{
		set_lst_active_rev(it, all);
		it = it->next;
	}
}
