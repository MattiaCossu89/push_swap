/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:51:52 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/17 16:36:33 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_all(t_all *all)
{
	free(all->in);
	free(all->insort);
	exit(1);
}

void	exit_error(t_all *all)
{
	ft_putstr_fd("Error\n", 2);
	exit_all(all);
}

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

void	sort_input(t_all *all)
{
	int		i;
	int		j;
	int		temp;

	i = all->len;
	if (!(all->insort = ft_calloc(all->len, sizeof(int))))
		exit_error(all);
	while (--i)
		all->insort[i] = i;
	while (i < all->len)
	{
		j = i - 1;
		while (++j < all->len)
		{
			if (all->in[all->insort[i]] > all->in[all->insort[j]])
			{
				temp = all->insort[i];
				all->insort[i] = all->insort[j];
				all->insort[j] = temp;
			}
		}
		i++;
	}
}

void	print_input(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->len)
	{
		ft_putnbr_fd(all->insort[i], 1);
		ft_putstr_fd(" -> ", 1);
		ft_putnbr_fd(all->in[all->insort[i]], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	print_stack(t_ilst *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putnbr_fd(lst->n, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
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
		new->ri = all->insort[i];
		if (!all->a.ss)
			ft_ilst_addfront(&all->a.ss, new);
		else
			ft_ilst_addback(&all->a.se, new);
		all->a.se = new;
		i++;
	}
	all->a.len = all->len;
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac == 1)
		exit(0);
	ft_bzero(&all, sizeof(t_all));
	insert_input(&all, ac, av);
	sort_input(&all);
	fill_stack_a(&all);
	print_input(&all);
	print_stack(all.a.ss);
}
