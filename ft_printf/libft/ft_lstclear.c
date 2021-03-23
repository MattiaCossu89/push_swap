/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:54:11 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/12 15:54:13 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;
	t_list *iter;

	iter = *lst;
	while (iter)
	{
		del(iter->content);
		temp = iter->next;
		free(iter);
		iter = temp;
	}
	*lst = 0;
}
