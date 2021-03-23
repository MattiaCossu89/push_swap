/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:26:17 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/20 16:16:42 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_uint(size_t nbr, int n_len, const char *base, t_par *g_cur)
{
	int	res;
	int	prec_off;

	res = 0;
	prec_off = (base[10] == 'a' || base[10] == 'A') && nbr &&
				g_cur->hflag ? 2 : 0;
	if (g_cur->hflag)
	{
		if (base[10] == 'a' && nbr)
			res += ft_putstr("0x", 2);
		else if (base[10] == 'A' && nbr)
			res += ft_putstr("0X", 2);
	}
	if (n_len < g_cur->prec_len)
		res += ft_putwidth(g_cur->prec_len - n_len, '0');
	else if (n_len < g_cur->width && g_cur->zflag && g_cur->prec_len < 0)
		res += ft_putwidth(g_cur->width - n_len - prec_off, '0');
	if (nbr || g_cur->prec_len)
		ft_putnbr_base(nbr, base);
	else
		n_len = 0;
	return (n_len + res);
}

static void	get_base(char type, t_par *g_cur)
{
	if (type == 'u')
		(g_cur->base = BASE_10);
	else if (type == 'x')
		(g_cur->base = BASE_16);
	else
		(g_cur->base = BASE_16X);
}

static void	set_length(size_t nbr, unsigned int *n_len,
					int *r_len, t_par *g_cur)
{
	if (nbr)
		*n_len = ft_nbrlen(nbr, ft_strlen(g_cur->base));
	if (nbr)
		*r_len = *n_len;
	else if (g_cur->prec_len < 0)
	{
		*n_len = 1;
		*r_len = 1;
	}
	else if (g_cur->prec_len == 0)
	{
		*n_len = 0;
		*r_len = 0;
	}
	else
	{
		*r_len = g_cur->prec_len;
		*n_len = 1;
	}
}

size_t		get_number(size_t nbr, t_par *g_cur)
{
	if (g_cur->h)
		return ((unsigned short)nbr & 0xffff);
	else if (g_cur->hh)
		return ((unsigned char)nbr & 0xff);
	else if (g_cur->l)
		return ((unsigned long)nbr & 0xffffffffffffffff);
	else if (g_cur->ll)
		return ((unsigned long long)nbr);
	else
		return (nbr & 0xffffffff);
	return (nbr);
}

char		p_req_u(size_t nbr, char type, t_par *g_cur)
{
	unsigned int	n_len;
	int				r_len;

	get_base(type, g_cur);
	nbr = get_number(nbr, g_cur);
	set_length(nbr, &n_len, &r_len, g_cur);
	r_len = (int)n_len > g_cur->prec_len ? (int)n_len : g_cur->prec_len;
	r_len += (type == 'x' || type == 'X') && g_cur->hflag && nbr ? 2 : 0;
	if (g_cur->mflag)
		g_cur->printed += print_uint(nbr, n_len, g_cur->base, g_cur);
	if (!g_cur->zflag || g_cur->prec_len >= 0)
		g_cur->printed += ft_putwidth(g_cur->width - r_len, ' ');
	if (!g_cur->mflag)
		g_cur->printed += print_uint(nbr, n_len, g_cur->base, g_cur);
	return (1);
}
