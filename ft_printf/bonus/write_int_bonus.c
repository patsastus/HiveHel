/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:30:40 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/09 10:59:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
#include "../libft/libft.h"

static void	handle_precision_sign(char **s, t_flag *flags, int i);
static void	handle_width(char **s, t_flag *flags);

int	write_int_bonus(int i, t_flag *flags)
{
	char	*temp;
	int		ret;

	temp = ft_itoa(i);
	handle_precision_sign(&temp, flags, i);
	handle_width(&temp, flags);
	ret = (write(1, temp, ft_strlen(temp)));
	free(temp);
	return (ret);
}

static void	handle_precision_sign(char **s, t_flag *flags, int i)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(*s);
	if (flags->prec && !(flags->precision) && !i)
	{
		free(*s);
		*s = ft_strdup("");
		return ;
	}
	if (i < 0)
		len--;
	if ((size_t)(flags->precision) > len)
	{
		temp = pad_zero(*s, flags->precision - len);
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

static void	handle_width(char **s, t_flag *flags)
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
		else if (flags->zero && !(flags->prec))
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
