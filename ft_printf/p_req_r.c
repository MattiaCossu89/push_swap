/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:47:51 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/20 14:46:42 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	p_req_r(t_par *g_cur)
{
	if (g_cur->mflag)
		g_cur->printed += ft_putchar_fd('%', 1);
	if (!g_cur->mflag)
		g_cur->printed += ft_putchar_fd('%', 1);
	return (1);
}
