/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:52:07 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/24 18:34:36 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nbr)
{
	int				len;
	unsigned int	n;

	len = 1;
	if (nbr < 0)
	{
		n = -nbr;
		len++;
	}
	else
		n = nbr;
	while (n /= 10)
		len++;
	return (len);
}
