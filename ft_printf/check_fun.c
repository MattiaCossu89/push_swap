/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:16:41 by mcossu            #+#    #+#             */
/*   Updated: 2021/03/27 15:42:10 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

t_par	*g_cur;

char	check_flags(const char **str, t_par *g_cur)
{
	if (**str == '-')
		return (set_mflag(str, g_cur));
	else if (**str == '0')
		return (set_zflag(str, g_cur));
	else if (**str == '#')
		return (set_hflag(str, g_cur));
	else if (**str == '+')
		return (set_pflag(str, g_cur));
	else if (**str == ' ')
		return (set_sflag(str, g_cur));
	return (0);
}

char	check_width(const char **str, t_par *g_cur)
{
	if (**str == '*')
	{
		g_cur->width = va_arg(g_cur->arg, int);
		if (g_cur->width < 0)
		{
			g_cur->width = -g_cur->width;
			g_cur->mflag = 'k';
			g_cur->zflag = 0;
		}
		(*str)++;
		return (1);
	}
	if (**str == '0')
		while (**str == '0')
			(*str)++;
	if (**str > '0' && **str <= '9')
	{
		g_cur->width = ft_atoi(*str);
		*str += nbr_len(g_cur->width, 10);
		return (1);
	}
	return (0);
}

char	check_preci(const char **str, t_par *g_cur)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			g_cur->prec_len = va_arg(g_cur->arg, int);
			(*str)++;
			return (1);
		}
		if (**str == '0')
			while (**str == '0')
				(*str)++;
		if (**str > '0' && **str <= '9')
		{
			g_cur->prec_len = ft_atoi(*str);
			*str += nbr_len(g_cur->prec_len, 10);
		}
		else
			g_cur->prec_len = 0;
		return (1);
	}
	return (0);
}

char	check_lenght(const char **str, t_par *g_cur)
{
	if (**str == 'l')
	{
		(*str)++;
		if (**str == 'l')
		{
			g_cur->ll = 'k';
			(*str)++;
		}
		else
			g_cur->l = 'k';
		return (1);
	}
	if (**str == 'h')
	{
		(*str)++;
		if (**str == 'h')
		{
			g_cur->hh = 'k';
			(*str)++;
		}
		else
			g_cur->h = 'k';
		return (1);
	}
	return (0);
}

void	check_all(const char **str, t_par *g_cur)
{
	while (check_flags(str, g_cur) || check_width(str, g_cur) ||
			check_preci(str, g_cur) || check_lenght(str, g_cur))
		;
}
