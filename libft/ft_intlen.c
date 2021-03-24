/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:52:07 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/24 18:33:51 by mcossu           ###   ########.fr       */
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
		n = -nbr
	}
	while (nbr /= 10)
		len++;
	return (len);
}
