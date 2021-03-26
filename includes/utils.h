/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:23:34 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 17:23:35 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct_def.h"

void	insert_input(t_all *all, char ***av);
void	init_input(t_all *all);
char	***parse_input(t_all *all, int ac, char **av);
void	sort_input(t_all *all);
void	print_input(t_all *all);
void	print_stack(t_ilst *lst);
void	fill_stack_a(t_all *all);
void	exit_all(t_all *all);
void	exit_error(t_all *all);
void	exit_error_avv(t_all *all, char ***av);
void	free_avv(char  ***avv);
int		min(int a, int b);
t_ilst	**ft_realloc_arr(t_ilst **in, size_t n);
void	clear_lists(t_all *all);
#endif
