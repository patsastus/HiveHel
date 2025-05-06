/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:11 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/06 09:43:47 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include "libft/libft.h"

static char	*make_str(unsigned long u, int *num_chars);
static void	ft_write_str(char *dest, unsigned long u, int num_chars);

char	*ft_itoa_hex(unsigned long u)
{
	char			*ret;
	int				num_chars;

	ret = make_str(u, &num_chars);
	if (!ret)
		return (NULL);
	ft_write_str(ret, u, num_chars);
	return (ret);
}

static void	ft_write_str(char *dest, unsigned long u, int num_chars)
{
	const char	*base;

	base = "0123456789abcdef";
	while (num_chars > 0)
	{
		dest[num_chars - 1] = base[u % 16];
		u /= 16;
		num_chars--;
	}
	return ;
}

static char	*make_str(unsigned long u, int *num_chars)
{
	*num_chars = 0;
	if (u == 0)
	{
		*num_chars = 1;
		return (ft_calloc(2, 1));
	}
	while (u != 0)
	{
		(*num_chars)++;
		u /= 16;
	}
	return (ft_calloc(*num_chars + 1, 1));
}
