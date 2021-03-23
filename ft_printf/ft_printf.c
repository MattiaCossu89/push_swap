/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:35:17 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/20 14:34:16 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	init_glob(t_par *g_cur)
{
	g_cur->sflag = 0;
	g_cur->zflag = 0;
	g_cur->pflag = 0;
	g_cur->hflag = 0;
	g_cur->mflag = 0;
	g_cur->prec = 0;
	g_cur->width = -1;
	g_cur->prec_len = -1;
	g_cur->res = 0;
	g_cur->error = 0;
	g_cur->base = 0;
	g_cur->l = 0;
	g_cur->ll = 0;
	g_cur->h = 0;
	g_cur->hh = 0;
}

char	check_str(const char *str, t_par *g_cur)
{
	while (*str)
	{
		if (*str == '%' && str++)
		{
			init_glob(g_cur);
			check_all(&str, g_cur);
			if (g_cur->error || !check_types(&str, "cspdiuxXn%"))
			{
				write(2, "Parse Error", 11);
				return (0);
			}
			str++;
		}
		else
			str++;
	}
	return ('k');
}

char	print_request(char type, va_list args, t_par *g_cur)
{
	if (type == 'c')
		return (p_req_c(va_arg(args, int), g_cur));
	else if (type == 's')
		return (p_req_s(va_arg(args, const char *), g_cur));
	else if (type == 'p')
		return (p_req_p(va_arg(args, size_t), g_cur));
	else if (type == 'd')
		return (p_req_d(va_arg(args, long long int), g_cur));
	else if (type == 'i')
		return (p_req_i(va_arg(args, long long int), g_cur));
	else if (type == 'u')
		return (p_req_u(va_arg(args, unsigned long long), 'u', g_cur));
	else if (type == 'x')
		return (p_req_u(va_arg(args, unsigned long long), 'x', g_cur));
	else if (type == 'X')
		return (p_req_u(va_arg(args, unsigned long long), 'X', g_cur));
	else if (type == '%')
		return (p_req_r(g_cur));
	else if (type == 'n')
		return (p_req_n(va_arg(args, int *), g_cur));
	return (0);
}

int		ft_print_str(const char *str, va_list args, t_par *g_cur)
{
	char chk;

	while (*str)
	{
		if (*str == '%' && str++)
		{
			init_glob(g_cur);
			check_all(&str, g_cur);
			chk = print_request(*str, args, g_cur);
			if (chk > 0)
				str += chk - 1;
			else
				return (-1);
		}
		else
			g_cur->printed += ft_putchar_fd(*str, 1);
		str++;
	}
	return (g_cur->printed);
}

int		ft_printf(const char *str, ...)
{
	int		res;
	t_par	*g_cur;
	t_par	curr;

	g_cur = &curr;
	init_glob(g_cur);
	g_cur->printed = 0;
	va_start(g_cur->arg, str);
	if (!check_str(str, g_cur))
		return (-1);
	va_end(g_cur->arg);
	va_start(g_cur->arg, str);
	res = ft_print_str(str, g_cur->arg, g_cur);
	if (g_cur->res)
		*(g_cur->res) = res;
	va_end(g_cur->arg);
	return (res);
}
