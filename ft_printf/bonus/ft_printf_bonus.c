/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:09:20 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/08 12:45:45 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf_bonus.h"

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
			temp = ft_convert_bonus(&s, &ap);
			if (temp >= 0)
			{
				count += temp;
			}
			else
				return (-1);
		}
		s++;
	}
	va_end(ap);
	return (count);
}
