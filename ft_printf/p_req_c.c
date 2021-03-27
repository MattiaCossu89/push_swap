/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:24:52 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/27 15:37:29 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_str(unsigned char *str, wchar_t c, size_t *sz)
{
	str[0] = ((c >> 18) & 0x07) | 0xF0;
	str[1] = ((c >> 12) & 0x3F) | 0x80;
	str[2] = ((c >> 6) & 0x3F) | 0x80;
	str[3] = ((c >> 0) & 0x3F) | 0x80;
	*sz = 4;
}

char	print_unicode(wchar_t c)
{
	unsigned char	str[4];
	size_t			sz;

	if (c < 0x80 && (sz = 1))
		str[0] = ((c >> 0) & 0x7F) | 0x00;
	else if (c < 0x0800)
	{
		str[0] = ((c >> 6) & 0x1F) | 0xC0;
		str[1] = ((c >> 0) & 0x3F) | 0x80;
		sz = 2;
	}
	else if (c < 0x010000)
	{
		str[0] = ((c >> 12) & 0x0F) | 0xE0;
		str[1] = ((c >> 6) & 0x3F) | 0x80;
		str[2] = ((c >> 0) & 0x3F) | 0x80;
		sz = 3;
	}
	else if (c < 0x110000)
		set_str(str, c, &sz);
	else
		return (0);
	write(1, str, sz);
	return (1);
}

char	p_req_c(int c, t_par *g_cur)
{
	if (g_cur->l)
		return (print_unicode(c));
	if (g_cur->mflag)
		g_cur->printed += ft_putchar_fd(c, 1);
	g_cur->printed += ft_putwidth(g_cur->width - 1, ' ');
	if (!g_cur->mflag)
		g_cur->printed += ft_putchar_fd(c, 1);
	return (1);
}
