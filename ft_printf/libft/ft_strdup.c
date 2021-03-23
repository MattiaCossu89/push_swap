/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:43:19 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 11:43:20 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *cpy;
	char *start;

	if (!(cpy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (0);
	start = cpy;
	while (*src)
		*(cpy++) = *(src++);
	*cpy = '\0';
	return (start);
}
