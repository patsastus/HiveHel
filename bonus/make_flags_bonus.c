/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flags_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:48:21 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:48:16 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "../libft/libft.h"

static int	set_conv(char *s, t_flag *flags);
static int	set_flags(char *s, t_flag *flags);
static int	set_width(char *s, t_flag *flags);
static int	set_precision(char *s, t_flag *flags);

t_flag	*make_flags_bonus(const char *s)
{
	t_flag	*flags;
	char	*temp;
	int		read;

	temp = (char *)s;
	flags = ft_calloc(sizeof(t_flag), 1);
	if (!flags || *temp != '%')
		return (NULL);
	read = 1;
	read += set_flags(temp + read, flags);
	read += set_width(temp + read, flags);
	read += set_precision(temp + read, flags);
	read += set_conv(temp + read, flags);
	flags->read = read;
	return (flags);
}

static int	set_conv(char *s, t_flag *flags)
{
	if (*s == 'c')
		flags->conv = CHAR;
	if (*s == 's')
		flags->conv = STR;
	if (*s == 'p')
		flags->conv = PTR;
	if (*s == 'd' || *s == 'i')
		flags->conv = INT;
	if (*s == 'u')
		flags->conv = UINT;
	if (*s == 'x')
		flags->conv = LOX;
	if (*s == 'X')
		flags->conv = HIX;
	if (*s == '%')
		flags->conv = PER;
	if (flags->conv != ERR)
		return (1);
	return (0);
}

static int	set_flags(char *s, t_flag *flags)
{
	int	read;

	read = 0;
	while (*s == '-' || *s == '0' || *s == '+' || *s == ' ' || *s == '#')
	{
		if (*s == '-')
			flags->minus = 1;
		if (*s == '0')
			flags->zero = 1;
		if (*s == '+')
			flags->plus = 1;
		if (*s == ' ')
			flags->space = 1;
		if (*s == '#')
			flags->hash = 1;
		read++;
		s++;
	}
	return (read);
}

static int	set_width(char *s, t_flag *flags)
{
	int	read;
	int	width;

	read = 0;
	width = 0;
	while (ft_isdigit(*(s + read)))
	{
		if (*s == '0' && read == 0)
			return (0);
		width *= 10;
		width += *(s + read) - '0';
		read++;
	}
	flags->width = width;
	return (read);
}

static int	set_precision(char *s, t_flag *flags)
{
	int	read;
	int	precision;

	read = 0;
	if (*s != '.')
		return (0);
	else
	{
		flags->precision = 1;
		read++;
	}
	precision = 0;
	while (ft_isdigit(*(s + read)))
	{
		precision *= 10;
		precision += *(s + read) - '0';
		read++;
	}
	flags->precision_value = precision;
	return (read);
}
