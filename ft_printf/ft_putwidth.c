/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:23:53 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/18 15:49:53 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putwidth(int nbr, char c)
{
	int res;

	res = nbr;
	while (nbr-- > 0)
		ft_putchar_fd(c, 1);
	return (res > 0 ? res : 0);
}
