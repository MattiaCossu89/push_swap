/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:25:37 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/20 14:46:29 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_pointer(size_t nbr, unsigned int n_len, t_par *g_cur)
{
	if (nbr)
		g_cur->printed += ft_putstr_fd("0x", 1);
	if ((g_cur->prec_len && g_cur->prec_len > 0) || nbr)
	{
		if (g_cur->prec_len > (int)n_len)
			g_cur->printed += ft_putwidth(g_cur->prec_len - n_len, '0');
		ft_putnbr_base(nbr, BASE_16);
	}
	else
	{
		g_cur->printed += ft_putstr_fd("(nil)", 1);
	}
}

char	p_req_p(size_t nbr, t_par *g_cur)
{
	unsigned int n_len;
	unsigned int add_len;

	n_len = ft_nbrlen(nbr, 16);
	add_len = 2;
	if (!nbr && (!g_cur->prec_len || g_cur->prec_len < 0))
	{
		n_len = 0;
		add_len = 5;
	}
	if (g_cur->mflag)
		p_pointer(nbr, n_len, g_cur);
	g_cur->printed +=
		ft_putwidth(g_cur->width - n_len - add_len, g_cur->zflag ? '0' : ' ');
	if (!g_cur->mflag)
		p_pointer(nbr, n_len, g_cur);
	g_cur->printed += n_len;
	return (1);
}
