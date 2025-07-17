/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:33:39 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:48:16 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../libft/libft.h"

static void	to_upper(unsigned int u, char *s);
static void	handle_flags(char **s, t_flag *flags, int i);
static void	handle_hash(char **s, t_flag *flags);
static void	handle_width(char **s, t_flag *flags);

int	write_hex_bonus(int i, t_flag *flags)
{
	char	*temp;
	int		ret;

	temp = ft_itoa_hex((unsigned int)i);
	if (flags->precision && !(flags->precision_value) && !i)
	{
		free(temp);
		temp = ft_strdup("");
	}
	if (!temp)
		return (-1);
	handle_flags(&temp, flags, i);
	if (!temp)
		return (-1);
	if (flags->conv == HIX)
		ft_striteri(temp, to_upper);
	ret = write(1, temp, ft_strlen(temp));
	free(temp);
	return (ret);
}

static void	to_upper(unsigned int u, char *s)
{
	(void)u;
	*s = ft_toupper(*s);
}

static void	handle_flags(char **s, t_flag *flags, int i)
{
	char	*temp;
	size_t	len;
	int		zero;

	zero = 0;
	if (i == 0)
		zero = 1;
	len = ft_strlen(*s);
	if ((size_t)flags->precision_value > len)
	{
		temp = pad_zero(*s, flags->precision_value - len);
		free(*s);
		*s = temp;
	}
	if (flags->hash && !zero)
		handle_hash(s, flags);
	handle_width(s, flags);
}

static void	handle_hash(char **s, t_flag *flags)
{
	char	*temp;
	size_t	len;

	if (!(*s))
		return ;
	len = ft_strlen(*s);
	if (flags->zero && !(flags->minus) && (size_t)(flags->width) > len + 2)
	{
		temp = pad_zero(*s, flags->width - len - 2);
		free(*s);
		*s = temp;
	}
	temp = ft_strjoin("0x", *s);
	free(*s);
	*s = temp;
}

static void	handle_width(char **s, t_flag *flags)
{
	char	*temp;

	if (!(*s))
		return ;
	if ((size_t)(flags->width) > ft_strlen(*s))
	{
		if (flags->minus)
		{
			temp = pad_s(*s, flags, ft_strlen(*s));
			free(*s);
			*s = temp;
		}
		else if (flags->zero && !(flags->precision))
		{
			temp = pad_zero(*s, flags->width - ft_strlen(*s));
			free(*s);
			*s = temp;
		}
		else
		{
			temp = pad_s(*s, flags, ft_strlen(*s));
			free(*s);
			*s = temp;
		}
	}
}
