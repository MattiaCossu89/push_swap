/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:55:33 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/24 18:27:48 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
