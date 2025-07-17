/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:51:27 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:48:16 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "../libft/libft.h"

/*
read string for characters that are legal conversion standards
*/
int	ft_convert_bonus(const char **s, va_list *ap)
{
	t_flag	*flags;
	int		count;

	flags = make_flags_bonus(*s);
	if (!flags || flags->conv == ERR)
		return (0);
	count = 0;
	if (flags->conv == CHAR)
		count = write_char_bonus((char)va_arg(*ap, int), flags);
	if (flags->conv == STR)
		count = write_str_bonus(va_arg(*ap, char *), flags);
	if (flags->conv == PTR)
		count = write_ptr_bonus(va_arg(*ap, void *), flags);
	if (flags->conv == INT)
		count = write_int_bonus(va_arg(*ap, int), flags);
	if (flags->conv == UINT)
		count = write_uint_bonus(va_arg(*ap, unsigned int), flags);
	if (flags->conv == LOX || flags->conv == HIX)
		count = write_hex_bonus(va_arg(*ap, int), flags);
	if (flags->conv == PER)
		count = write(1, "%", 1);
	*s += flags->read - 1;
	free(flags);
	return (count);
}
