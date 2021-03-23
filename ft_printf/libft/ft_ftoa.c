/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:14:37 by mcossu            #+#    #+#             */
/*   Updated: 2021/01/20 10:42:11 by mcossu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int n_tu(int number, int count)
{
    int result = 1;
    while(count-- > 0)
        result *= number;

    return result;
}

/*** Convert float to string ***/
char *ft_ftoa(double f, char r[])
{
    long long int length, length2, i, number, position, sign;
    double number2;

    sign = -1;   // -1 == positive number
    if (f < 0)
    {
        sign = '-';
        f *= -1;
    }

    number2 = f;
    number = f;
    length = 0;  // Size of decimal part
    length2 = 0; // Size of tenth

    /* Calculate length2 tenth part */
    while( (number2 - (double)number) != 0.0 && !((number2 - (double)number) < 0.0) )
    {
         number2 = f * (n_tu(10.0, length2 + 1));
         number = number2;

         length2++;
    }

    /* Calculate length decimal part */
    for (length = (f > 1) ? 0 : 1; f > 1; length++)
        f /= 10;

    position = length;
    length = length + 1 + length2;
    number = number2;
    if (sign == '-')
    {
        length++;
        position++;
    }

    for (i = length; i >= 0 ; i--)
    {
        if (i == (length))
            r[i] = '\0';
        else if(i == (position))
            r[i] = '.';
        else if(sign == '-' && i == 0)
            r[i] = '-';
        else
        {
            r[i] = (number % 10) + '0';
            number /=10;
        }
    }
	return (0);
}
// char	*ft_ftoa(double nbr)
// {
// 	char	*out;
// 	char	*out1;
// 	int		i;
// 	int		ti;
// 	double	f;

// 	f = (double)nbr;
// 	i = (int)f;
// 	out = ft_itoa(i);
// 	f -= i;
// 	i = 0;
// 	ti = 0;
// 	while (f > 0)
// 	{
// 		printf("(%f) ", f);
// 		f *= 10;
// 		i = (int)f;
// 		f -= (float)i;
// 		ti = (ti * 10) + i;
// 	}
// 	out = ft_strjoin(out, ".");
// 	out = ft_strjoin(out, (out1 = ft_itoa(ti)));
// 	return (out);
// }
