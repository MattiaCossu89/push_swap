/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:23:18 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 17:23:19 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "struct_def.h"

# define NRM  "\x1B[0m"
# define BLK  "\x1B[30m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

void	print_input(t_all *all);
void	print_stack(t_ilst *lst);
void	print_stacks(t_all *all);
void	print_sorted(t_all *all, int i);
void	print_body(t_all *all);
void	print_stack(t_ilst *lst);
void	print_line(t_all *all);
void	print_head(t_all *all);
void	print_stat(t_all *all);
void	mnm_a(t_all *all, t_ilst **min, t_ilst **max);
int		pos_a(t_all *all, t_ilst *tof);
#endif
