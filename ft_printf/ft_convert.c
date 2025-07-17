/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:30:06 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:56:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	handle_flags(t_flag *flags, va_list *ap);

/*
read string for characters that are legal conversion standards
*/
int	ft_convert(const char *s, va_list *ap)
{
	t_flag	*flags;
	int		count;

	flags = make_flags(s);
	if (!flags)
		return (-1);
	count = handle_flags(flags, ap);
	free(flags);
	return (count);
}

static int	handle_flags(t_flag *flags, va_list *ap)
{
	int	count;

	count = 0;
	if (flags->conv == CHAR)
		count = write_char((char)va_arg(*ap, int));
	if (flags->conv == STR)
		count = write_str(va_arg(*ap, char *));
	if (flags->conv == PTR)
		count = write_ptr(va_arg(*ap, void *));
	if (flags->conv == INT)
		count = write_int(va_arg(*ap, int));
	if (flags->conv == UINT)
		count = write_uint(va_arg(*ap, unsigned int));
	if (flags->conv == LOX)
		count = write_hex(va_arg(*ap, int), 0);
	if (flags->conv == HIX)
		count = write_hex(va_arg(*ap, int), 1);
	if (flags->conv == PER)
		count = (write(1, "%", 1));
	if (flags->conv == ERR)
		count = -1;
	return (count);
}
