/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:34:48 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/26 18:35:23 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	avait_n(t_all *all)
{
	int c;

	c = 0;
	if (all->fd)
		while (c != '\n')
			read(0, &c, 1);
	if (all->ft)
		while (c++ < 500000000)
			;
}
