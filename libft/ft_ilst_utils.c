/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilst_define.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:12:13 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/17 15:46:52 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ilst	*ft_ilst_new(int num)
{
	t_ilst *new;

	if (!(new = ft_calloc(1, sizeof(t_ilst))))
		return (0);
	new->n = num;
	new->prev = new;
	new->next = new;
	return (new);
}

t_ilst	*ft_ilst_last(t_ilst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_ilst	*ft_ilst_first(t_ilst *lst)
{
	if (!lst)
		return (0);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
