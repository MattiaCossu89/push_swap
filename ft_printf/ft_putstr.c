/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:23:13 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/18 16:23:40 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_par	*g_cur;

int	ft_putstr(const char *str, size_t len)
{
	int			res;
	const char	*p_str;

	p_str = str;
	if (!str && len >= 6)
		p_str = "(null)";
	else if (!str)
		len = 0;
	res = (int)len;
	while ((res)-- > 0)
		ft_putchar_fd(*(p_str++), 1);
	return (len);
}
