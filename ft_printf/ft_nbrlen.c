/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:21:36 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/18 16:21:37 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_nbrlen(size_t nbr, unsigned int b_len)
{
	unsigned int len;

	len = 1;
	while (nbr /= b_len)
		len++;
	return (len);
}
