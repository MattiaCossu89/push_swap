/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:04:19 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/17 16:35:12 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

# include "../libft/libft.h"

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

typedef struct	s_all
{
	int		*in;
	t_ilst	**insort;
	t_stack	a;
	t_stack	b;
	t_maxs	m;
	t_maxs	rm;
	int		len;
	char	print;
}				t_all;

#endif
