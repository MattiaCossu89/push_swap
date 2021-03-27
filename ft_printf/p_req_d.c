/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:30:25 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/27 15:38:50 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		get_sign(long long int nbr, t_par *g_cur)
{
	if (g_cur->h)
	{
		if ((short)nbr < 0)
			return (1);
	}
	else if (g_cur->hh)
	{
		if ((char)nbr < 0)
			return (1);
	}
	else if (g_cur->l)
	{
		if ((long int)nbr < 0)
			return (1);
	}
	else if (g_cur->ll)
		return (nbr >= 0 ? 0 : 1);
	else
	{
		if ((int)nbr < 0)
			return (1);
	}
	return (0);
}

static int		print_int(size_t nbr, int n_len, long long n, t_par *g_cur)
{
	int				res;
	char			sign;
	char			psign;

	res = 0;
	sign = get_sign(n, g_cur);
	psign = (sign == 0 && (g_cur->sflag || g_cur->pflag)) ? 1 : 0;
	if (sign)
		ft_putchar_fd('-', 1);
	else if (g_cur->pflag)
		res += ft_putwidth(1, '+');
	else if (g_cur->sflag)
		res += ft_putwidth(1, ' ');
	if (n_len < g_cur->prec_len)
		res += ft_putwidth(g_cur->prec_len - n_len, '0');
	else if (n_len < g_cur->width && g_cur->zflag && g_cur->prec_len < 0)
		res += ft_putwidth(g_cur->width - n_len - sign - psign, '0');
	if (nbr || g_cur->prec_len)
		ft_putnbr_base(nbr, BASE_10);
	else
		n_len = 0;
	return (n_len + sign + res);
}

static size_t	get_number(long long int nbr, t_par *g_cur)
{
	if (g_cur->h)
		return (get_s_num(nbr));
	else if (g_cur->hh)
		return (get_ss_num(nbr));
	else if (g_cur->l)
		return (get_l_num(nbr));
	else if (g_cur->ll)
		return (get_ll_num(nbr));
	else
		return (get_i_num(nbr));
	return (nbr);
}

char			p_req_d(long long int nbr, t_par *g_cur)
{
	unsigned int	n_len;
	int				r_len;
	char			sign;
	size_t			n;

	n = get_number(nbr, g_cur);
	n_len = ft_nbrlen(n, 10);
	if (nbr)
		r_len = (int)n_len > g_cur->prec_len ? (int)n_len : g_cur->prec_len;
	else if (g_cur->prec_len < 0)
		r_len = 1;
	else if (g_cur->prec_len == 0)
		r_len = 0;
	else
		r_len = g_cur->prec_len;
	sign = get_sign(nbr, g_cur);
	sign += (sign == 0 && (g_cur->sflag || g_cur->pflag)) ? 1 : 0;
	if (g_cur->mflag)
		g_cur->printed += print_int(n, n_len, nbr, g_cur);
	if (!g_cur->zflag || g_cur->prec_len >= 0)
		g_cur->printed += ft_putwidth(g_cur->width - r_len - sign, ' ');
	if (!g_cur->mflag)
		g_cur->printed += print_int(n, n_len, nbr, g_cur);
	return (1);
}

char			p_req_i(long long int nbr, t_par *g_cur)
{
	return (p_req_d(nbr, g_cur));
}
