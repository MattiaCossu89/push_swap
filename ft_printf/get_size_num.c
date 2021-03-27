/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:33:13 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/27 15:33:38 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			get_s_num(long long int nbr)
{
	if ((short)nbr < 0)
		nbr = -nbr;
	nbr = (nbr & 0x0000ffff);
	return (nbr);
}

size_t			get_ss_num(long long int nbr)
{
	if (((char)nbr < 0))
		nbr = -nbr;
	nbr = (nbr & 0x000000ff);
	return (nbr);
}

size_t			get_l_num(long long int nbr)
{
	if ((long int)nbr < 0)
		nbr = -nbr;
	nbr = (nbr & 0xffffffffffffffff);
	return (nbr);
}

size_t			get_ll_num(long long int nbr)
{
	size_t n;

	n = nbr;
	if (nbr < 0)
		n = -nbr;
	return (n);
}

size_t			get_i_num(long long int nbr)
{
	if ((int)nbr < 0)
		nbr = -nbr;
	nbr = (nbr & 0xffffffff);
	return (nbr);
}
