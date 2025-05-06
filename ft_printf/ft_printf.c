/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:04:19 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/06 10:10:06 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	long	count;
	int		temp;

	va_start(ap, s);
	count = 0;
	while (*s)
	{
		if (*s != '%')
			count += write(1, s, 1);
		else
		{
			temp = ft_convert(s, &ap);
			if (temp)
			{
				count += temp;
				s++;
			}
			else
				return (-1);
		}
		s++;
	}
	va_end(ap);
	return (count);
}
