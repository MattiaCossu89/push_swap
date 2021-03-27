/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:45:24 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/27 15:38:14 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_lstrlen(wchar_t *str)
{
	size_t len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int		ft_putlstr(wchar_t *str, size_t len)
{
	int			res;
	wchar_t		*p_str;

	res = (int)len;
	p_str = str;
	if (!str && len >= 6)
		p_str = L"(null)";
	else if (!str)
		len = 0;
	res = (int)len;
	while ((res)--)
		write(1, (p_str++), 1);
	return (len);
}

char	p_req_ls(wchar_t *str, t_par *g_cur)
{
	size_t f_len;
	size_t s_len;

	if (!str && g_cur->prec_len < 6 && g_cur->prec_len >= 0)
		f_len = 0;
	else if (!str)
		f_len = 6;
	else
	{
		s_len = ft_lstrlen(str);
		if (g_cur->prec_len >= 0)
			f_len = s_len > (size_t)g_cur->prec_len ?
				(size_t)g_cur->prec_len : s_len;
		else
			f_len = s_len;
	}
	if (g_cur->mflag)
		g_cur->printed += ft_putlstr(str, f_len);
	g_cur->printed +=
		ft_putwidth(g_cur->width - (int)f_len, ' ');
	if (!g_cur->mflag)
		g_cur->printed += ft_putlstr(str, f_len);
	return (1);
}

char	p_req_s(const char *str, t_par *g_cur)
{
	size_t f_len;
	size_t s_len;

	if (g_cur->l)
		return (p_req_ls((wchar_t *)str, g_cur));
	if (!str && g_cur->prec_len < 6 && g_cur->prec_len >= 0)
		f_len = 0;
	else if (!str)
		f_len = 6;
	else
	{
		s_len = ft_strlen(str);
		if (g_cur->prec_len >= 0)
			f_len = s_len > (size_t)g_cur->prec_len ?
				(size_t)g_cur->prec_len : s_len;
		else
			f_len = s_len;
	}
	if (g_cur->mflag)
		g_cur->printed += ft_putstr(str, f_len);
	g_cur->printed +=
		ft_putwidth(g_cur->width - (int)f_len, ' ');
	if (!g_cur->mflag)
		g_cur->printed += ft_putstr(str, f_len);
	return (1);
}
