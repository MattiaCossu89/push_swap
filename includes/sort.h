/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:23:25 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 17:23:25 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "struct_def.h"

void	find_pos_a(t_all *all, t_ilst *tof, t_sol *sol);
t_sol	find_best_candidate(t_all *all, t_sol *sol);
int		find_pos_f(t_all *all);
int		find_pos_l(t_all *all);
void	find_mnm(t_ilst *lst, int *min, int *max);
void	compute_sorting(t_all *all);
t_ilst	**ft_realloc_arr(t_ilst **in, size_t n);
void	set_stacks(t_all *all);
void	sort(t_all *all);
void	sort_three(t_all *all);
void	little_sort(t_all *all);
void	find_max_sub(t_all *all);
void	get_best_sol(t_all *all, t_sol *sol, t_ilst *tof, int i);
void	restore_stack(t_all *all);
void	push_back_minnmax(t_all *all);
#endif
