/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:25:33 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 18:57:46 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lis(t_all *all)
{
	int i;

	i = 0;
	while (i < all->m.len)
	{
		printf("%d ", all->m.active[i]->n);
		i++;
	}
	printf("\n");
	sleep(100);
}

void	compute_sorting(t_all *all)
{
	find_max_sub(all);
	clear_lists(all);
	all->print = 1;
	if (all->len < 4 || all->len == all->m.len)
	{
		sort_three(all);
		return ;
	}
	if (all->len > 5)
	{
		set_stacks(all);
		push_back_minnmax(all);
		sort(all);
	}
	else
		little_sort(all);
}

void	init_file(t_all *all)
{
	if (!(all->file = open("res", O_WRONLY | O_CREAT | O_TRUNC, 0777)))
		exit_all(all);
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac == 1)
		exit(1);
	ft_bzero(&all, sizeof(t_all));
	all.p = 1;
	insert_input(&all, parse_input(&all, ac, av));
	fill_stack_a(&all);
	sort_input(&all);
	if (all.ff)
		init_file(&all);
	compute_sorting(&all);
	exit_all(&all);
	return (0);
}
