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

void	ft_ilst_addfront(t_ilst **lst, t_ilst *new)
{
	t_ilst *temp;

	if (!*lst)
	{
		*lst = new;
		new->prev = new;
		new->next = new;
		return ;
	}
	temp = *lst;
	*lst = new;
	new->next = temp;
	new->prev = temp->prev;
	new->prev->next = new;
	temp->prev = new;
}

void	ft_ilst_addback(t_ilst **lst, t_ilst *new)
{
	t_ilst *last;

	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*lst)->prev;
	new->prev = last;
	last->next = new;
	new->next = (*lst);
	(*lst)->prev = new;
}

void	ft_ilst_clear(t_ilst **lst)
{
	t_ilst *temp;
	t_ilst *first;

	if (!*lst)
		return ;
	first = (*lst);
	(*lst) = (*lst)->next;
	while (*lst != first)
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
	}
	free(*lst);
	*lst = 0;
}

t_ilst	*ft_dup_ilst(t_ilst *lst)
{
	t_ilst *new;
	t_ilst *temp;
	t_ilst *first;

	if (!(new = 0) && !lst)
		return (0);
	first = lst->prev;
	while (lst != first)
	{
		if (!(temp = ft_ilst_new(lst->n)))
		{
			ft_ilst_clear(&new);
			return (0);
		}
		ft_ilst_addback(&new, temp);
		temp->ri = lst->ri;
		lst = lst->next;
	}
	if (!(temp = ft_ilst_new(lst->n)))
		ft_ilst_clear(&new);
	if (!temp)
		return (0);
	ft_ilst_addback(&new, temp);
	temp->ri = lst->ri;
	return (new);
}
