/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:51:52 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/16 12:35:07 by mcossu           ###   ########.fr       */
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
		if (ft_strlen(av[i]) != ft_intlen(all->in[i - 1]))
			exit_error(all);
		i++;
	}
}

void	print_input(t_all *all)
{
	int		i;

	i = 0;
	while (all->in[i])
	{
		ft_putnbr_fd(all->in[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	fill_stack_a(t_all *all)
{
	t_ilst	*new;
	int		i;

	i = 0;
	while ()
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac == 1)
		exit(0);
	ft_bzero(&all, sizeof(t_all));
	insert_input(&all, ac, av);
	print_input(&all);
}
