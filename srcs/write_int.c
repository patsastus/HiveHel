/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:30:40 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/25 11:43:06 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

static void	handle_precision_sign(char **s, t_printf_flag *flags, int i);
static void	handle_width(char **s, t_printf_flag *flags);

int	write_int(int i, t_printf_flag *flags)
{
	char	*temp;
	int		ret;

	temp = ft_itoa(i);
	if (!temp)
		return (-1);
	handle_precision_sign(&temp, flags, i);
	if (!temp)
		return (-1);
	handle_width(&temp, flags);
	if (!temp)
		return (-1);
	ret = (write(1, temp, ft_strlen(temp)));
	free(temp);
	return (ret);
}

static void	handle_precision_sign(char **s, t_printf_flag *flags, int i)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(*s);
	if (flags->precision && !(flags->precision_value) && !i)
	{
		free(*s);
		*s = ft_strdup("");
		return ;
	}
	if (i < 0)
		len--;
	if ((size_t)(flags->precision_value) > len)
	{
		temp = pad_zero(*s, flags->precision_value - len);
		free(*s);
		*s = temp;
	}
	if (i >= 0)
	{
		if (flags->plus)
			pad_sign(s, '+');
		else if (flags->space)
			pad_sign(s, ' ');
	}
}

static void	handle_width(char **s, t_printf_flag *flags)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(*s);
	if ((size_t)(flags->width) > len)
	{
		if (flags->minus)
		{
			temp = pad_s(*s, flags, len);
			free(*s);
			*s = temp;
		}
		else if (flags->zero && !(flags->precision))
		{
			temp = pad_zero(*s, flags->width - len);
			free(*s);
			*s = temp;
		}
		else
		{
			temp = pad_s(*s, flags, len);
			free(*s);
			*s = temp;
		}
	}
}
