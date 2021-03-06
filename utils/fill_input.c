/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:24:57 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 17:31:28 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_func.h"

int		calc_len(char ***av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			j++;
		len += j;
		i++;
	}
	return (len);
}

void	insert_input(t_all *all, char ***av)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = -1;
	k = -1;
	if (!(all->in = ft_calloc(calc_len(av) + 1, sizeof(int))))
		exit_error(all);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isnumber(av[i][j]))
				exit_error_avv(all, av);
			all->in[++k] = ft_atoi(av[i][j]);
			if ((len = (int)ft_strlen(av[i][j])) != ft_intlen(all->in[k]))
				exit_error_avv(all, av);
			if (len > all->maxnl)
				all->maxnl = len;
		}
	}
	free_avv(av);
	all->len = k + 1;
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
