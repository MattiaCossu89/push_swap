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

void	ft_ilst_addfront(t_ilst **lst, t_ilst *new)
{
	t_ilst *temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	*lst = new;
	new->next = temp;
	temp->prev = new;
}

void	ft_ilst_addback(t_ilst **lst, t_ilst *new)
{
	t_ilst *last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_ilst_last(*lst);
	last->next = new;
	new->prev = last;
}

void	ft_ilst_clear(t_ilst **lst)
{
	t_ilst *temp;

	if (!*lst)
		return ;
	while ((*lst)->prev)
		(*lst) = (*lst)->prev;
	while (*lst)
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
	}
}

t_ilst	*ft_dup_ilst(t_ilst *lst)
{
	t_ilst *new;
	t_ilst *temp;

	if (!lst)
		return (0);
	new = 0;
	while (lst->next)
	{
		if (!(temp = ft_ilst_new(lst->n)))
		{
			ft_ilst_clear(&new);
			return (0);
		}
		ft_ilst_addback(&new, temp);
		new = temp;
		lst = lst->next;
	}
	return (ft_ilst_first(new));
}
