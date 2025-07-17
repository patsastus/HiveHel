/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:00:59 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/09 10:57:02 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "../libft/libft.h"

//return a space padded string of the character according to flags
char	*pad_c(char c, t_flag *flags)
{
	int		i;
	char	*ret;

	ret = ft_calloc(flags->width + 1, 1);
	if (!ret)
		return (NULL);
	i = 0;
	if (flags->minus)
	{
		ret[i++] = c;
		while (i < flags->width)
			ret[i++] = ' ';
	}
	else
	{
		while (i < flags->width)
			ret[i++] = ' ';
		ret[i - 1] = c;
	}
	return (ret);
}

//return a copy of s, taking strlen as len, either left- or right-padded
//with spaces according to flags
char	*pad_s(char *s, t_flag *flags, int len)
{
	int		pad;
	char	*ret;

	pad = flags->width - len;
	ret = ft_calloc(flags->width + 1, 1);
	if (!ret)
		return (NULL);
	if (flags->minus)
		ft_strlcpy(ret, s, len + 1);
	else
		ft_strlcpy(ret + pad, s, len + 1);
	while (pad > 0)
	{
		if (flags->minus)
			ret[ft_strlen(s) + pad - 1] = ' ';
		else
			ret[pad - 1] = ' ';
		pad--;
	}
	return (ret);
}

//return a copy of s leftpadded with n number of '0', with a possible 
//sign as the first char
char	*pad_zero(char *s, int n)
{
	size_t	len;
	char	*ret;
	char	sign;

	len = ft_strlen(s);
	sign = 0;
	if (*s == '-' || *s == '+' || *s == ' ')
		sign = 1;
	ret = ft_calloc(len + n + 1, 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret + n + sign, s + sign, len - sign + 1);
	while (n > 0)
	{
		ret[n - 1 + sign] = '0';
		n--;
	}
	if (sign)
		ret[0] = *s;
	return (ret);
}

//add a sign to the front of the string pointed to in *s, freeing the original
void	pad_sign(char **s, char c)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(*s);
	temp = ft_calloc(len + 2, 1);
	if (temp)
	{
		ft_strlcpy(temp + 1, *s, len + 1);
		*temp = c;
		free(*s);
		*s = temp;
	}
}
