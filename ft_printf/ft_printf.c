/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:04:19 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:56:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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
			temp = write(1, s, 1);
		else
		{
			temp = ft_convert(s, &ap);
			++s;
		}
		if (temp != -1)
		{
			count += temp;
			s++;
		}
		else
			return (-1);
	}
	va_end(ap);
	return (count);
}
