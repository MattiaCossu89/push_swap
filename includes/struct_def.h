/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:04:19 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/25 17:00:43 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct	s_stack
{
	int		len;
	t_ilst	*ss;
	t_ilst	*se;
}				t_stack;

typedef struct	s_maxs
{
	int		i;
	int		ifound;
	int		len;
	int		*lens;
	t_lst	*subs;
	t_lst	*found;
	t_ilst	**active;
}				t_maxs;

typedef struct	s_sol
{
	int		br;
	int		ar;
	char	equ;
}				t_sol;

typedef struct	s_ops
{
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		tot;
}				t_ops;


typedef struct	s_all
{
	int		*in;
	t_ilst	**insort;
	t_stack	a;
	t_stack	b;
	t_maxs	m;
	t_maxs	rm;
	int		len;
	int		file;
	int		maxnl;
	char	print;
	char	fc;
	char	ff;
	char	fs;
	char	fv;
	char	p;
	t_ops	op;
}				t_all;

# define ABS(x) (x < 0 ? -x : x)
# define SIGN(x) (x < 0 ? -1 : 1)
#endif
