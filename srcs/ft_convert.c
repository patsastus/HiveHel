/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:51:27 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/25 14:51:24 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

/*
read string for characters that are legal conversion standards
*/
int	ft_printf_convert(const char **s, va_list *ap)
{
	t_printf_flag	*flags;
	int				count;

	flags = make_flags(*s);
	if (!flags || flags->conv == ERR)
		return (0);
	count = 0;
	if (flags->conv == CHAR)
		count = write_char((char)va_arg(*ap, int), flags);
	if (flags->conv == STR)
		count = write_str(va_arg(*ap, char *), flags);
	if (flags->conv == PTR)
		count = write_ptr(va_arg(*ap, void *), flags);
	if (flags->conv == INT)
		count = write_int(va_arg(*ap, int), flags);
	if (flags->conv == UINT)
		count = write_uint(va_arg(*ap, unsigned int), flags);
	if (flags->conv == LOX || flags->conv == HIX)
		count = write_hex(va_arg(*ap, int), flags);
	if (flags->conv == PER)
		count = write(1, "%", 1);
	*s += flags->read - 1;
	free(flags);
	return (count);
}
