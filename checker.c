/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:51:52 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/17 19:03:47 by mcossu           ###   ########.fr       */
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

void	init_input(t_all *all)
{
	int i;

	i = all->len;
	if (!(all->insort = ft_calloc(all->len, sizeof(int))))
		exit_error(all);
	while (--i)
		all->insort[i] = i;
}

void	sort_input(t_all *all)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	init_input(all);
	while (i < all->len)
	{
		j = i;
		while (++j < all->len)
		{
			if (all->in[all->insort[i]] == all->in[all->insort[j]])
				exit_error(all);
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

void	compute_command(t_all *all, char *line)
{
	if (!ft_strncmp(line, "sa", 4))
		sa(all);
	else if (!ft_strncmp(line, "sb", 4))
		sb(all);
	else if (!ft_strncmp(line, "ss", 4))
		ss(all);
	else if (!ft_strncmp(line, "pa", 4))
		pa(all);
	else if (!ft_strncmp(line, "pb", 4))
		pb(all);
	else if (!ft_strncmp(line, "ra", 4))
		ra(all);
	else if (!ft_strncmp(line, "rb", 4))
		rb(all);
	else if (!ft_strncmp(line, "rr", 4))
		rr(all);
	else if (!ft_strncmp(line, "rra", 4))
		rra(all);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(all);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(all);
	else
		exit_error(all);
}

void	get_in(t_all *all)
{
	char	*line;
	int		res;

	line = 0;
	while ((res = get_next_line(0, &line)) > 0)
	{
		ft_putstr_fd("----------\n", 1);
		compute_command(all, line);
		print_stack(all->a.ss);
		ft_putstr_fd("*******\n", 1);
		print_stack(all->b.ss);
		ft_putstr_fd("----------\n", 1);
		free(line);
		line = 0;
	}
	free(line);
}

void	check_out(t_all *all)
{
	t_ilst *a;

	if (all->b.ss)
	{
		ft_putstr_fd(RED"KO\n"NRM, 1);
		exit_all(all);
	}
	a = all->a.ss;
	while (a->next)
	{
		if (a->n > a->next->n)
		{
			ft_putstr_fd(RED"KO\n"NRM, 1);
			exit_all(all);
		}
		a = a->next;
	}
	ft_putstr_fd(GRN"OK\n"NRM, 1);
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac == 1)
		exit(1);
	ft_bzero(&all, sizeof(t_all));
	insert_input(&all, ac, av);
	sort_input(&all);
	fill_stack_a(&all);
	print_input(&all);
	print_stack(all.a.ss);
	get_in(&all);
	check_out(&all);
	return (0);
}
