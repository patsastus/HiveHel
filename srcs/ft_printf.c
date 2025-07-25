/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:09:20 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/25 10:28:52 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h> 

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
			temp = ft_printf_convert(&s, &ap);
		if (temp >= 0)
		{
			count += temp;
			++s;
		}
		else
			return (-1);
	}
	va_end(ap);
	return (count);
}
