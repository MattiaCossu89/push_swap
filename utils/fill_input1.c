/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_input1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:30:20 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 18:33:49 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_func.h"

void	free_arr(char **arr)
{
	int j;

	j = -1;
	while (arr[++j])
		free(arr[j]);
	free(arr);
}

int		fill_f(t_all *all, char flag)
{
	if (flag == 'c' && !all->fc && !all->p)
		all->fc = 'c';
	else if (flag == 'f' && !all->ff)
		all->ff = 'f';
	else if (flag == 'v' && !all->fv && !all->p)
		all->fv = 'v';
	else if (flag == 's' && !all->fs && !all->p)
		all->fs = 's';
	else if (flag == 'd' && !all->fd && all->p)
		all->fd = 'd';
	else if (flag == 't' && !all->ft && all->p)
		all->ft = 't';
	else
		return (0);
	return (1);
}

int		fill_flags(t_all *all, char *flags, int *i)
{
	if (ft_isnumber(flags))
		return (1);
	if (*flags != '-')
		return (0);
	flags++;
	while (ft_is_in_charset(*flags, "cfsvdt"))
	{
		if (!fill_f(all, *flags))
			return (0);
		flags++;
	}
	if (*flags)
		return (0);
	(*i)++;
	return (1);
}

char	***parse_input(t_all *all, int ac, char **av)
{
	char	***avv;
	int		i;
	int		j;
	char	**a;

	i = 0;
	j = -1;
	a = ft_split(av[1], ' ');
	if (!(fill_flags(all, a[0], &i)))
	{
		free_arr(a);
		exit_error(all);
	}
	free_arr(a);
	if (!(avv = ft_calloc(ac, sizeof(char **))))
		exit_error(all);
	while (++i < ac)
	{
		if (!(avv[++j] = ft_split(av[i], ' ')))
		{
			free_avv(avv);
			exit_error(all);
		}
	}
	return (avv);
}
