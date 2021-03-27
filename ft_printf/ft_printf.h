/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:37:12 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/27 15:39:00 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

# define BASE_10	"0123456789"
# define BASE_16	"0123456789abcdef"
# define BASE_16X	"0123456789ABCDEF"
# define BASE_8		"01234567"

typedef struct	s_par
{
	char		mflag;
	char		zflag;
	char		sflag;
	char		hflag;
	char		pflag;
	char		prec;
	char		h;
	char		hh;
	char		l;
	char		ll;
	int			width;
	int			prec_len;
	int			printed;
	char		error;
	int			*res;
	const char	*base;
	va_list		arg;
}				t_par;

int				ft_printf(const char *str, ...);
char			check_flags(const char **str, t_par *g_cur);
char			check_width(const char **str, t_par *g_cur);
char			check_preci(const char **str, t_par *g_cur);
void			check_all(const char **str, t_par *g_cur);
char			check_types(const char **str, const char *charset);
int				ft_putwidth(int nbr, char c);
int				ft_putstr(const char *str, size_t len);
unsigned int	ft_nbrlen(size_t nbr, unsigned int b_len);
char			p_req_c(int c, t_par *g_cur);
char			p_req_s(const char *str, t_par *g_cur);
char			p_req_p(size_t nbr, t_par *g_cur);
char			p_req_d(long long int nbr, t_par *g_cur);
char			p_req_i(long long int nbr, t_par *g_cur);
char			p_req_u(size_t nbr, char type, t_par *g_cur);
char			p_req_r(t_par *g_cur);
char			p_req_n(int *ptr, t_par *g_cur);
char			set_mflag(const char **str, t_par *g_cur);
char			set_zflag(const char **str, t_par *g_cur);
char			set_hflag(const char **str, t_par *g_cur);
char			set_pflag(const char **str, t_par *g_cur);
char			set_sflag(const char **str, t_par *g_cur);
size_t			get_s_num(long long int nbr);
size_t			get_ss_num(long long int nbr);
size_t			get_l_num(long long int nbr);
size_t			get_ll_num(long long int nbr);
size_t			get_i_num(long long int nbr);
#endif
