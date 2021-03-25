/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:51:52 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/25 14:28:48 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		compute_command(all, line);
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
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	a = all->a.ss;
	while (a != all->a.ss->prev)
	{
		if (a->n > a->next->n)
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		a = a->next;
	}
	ft_putstr_fd("OK\n", 1);
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac == 1)
		return (1);
	ft_bzero(&all, sizeof(t_all));
	insert_input(&all, parse_input(&all, ac, av));
	fill_stack_a(&all);
	get_in(&all);
	check_out(&all);
	exit_all(&all);
	return (0);
}
