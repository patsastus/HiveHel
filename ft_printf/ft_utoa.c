/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:08:02 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/30 12:47:56 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include "libft/libft.h"

static char	*make_str(unsigned int u, int *num_digits);
static void	ft_write_str(unsigned int u, char *buf, int num_digits);

char	*ft_utoa(unsigned int u)
{
	char	*ret;
	int		num_digits;

	ret = make_str(u, &num_digits);
	if (ret == NULL)
		return (NULL);
	ft_write_str(u, ret, num_digits);
	return (ret);
}

static void	ft_write_str(unsigned int u, char *buf, int num_digits)
{
	const char	*base;

	base = "0123456789";
	while (num_digits > 0)
	{
		buf[num_digits - 1] = base[u % 10];
		u /= 10;
		num_digits--;
	}
	return ;
}

static char	*make_str(unsigned int u, int *num_digits)
{
	char			*ret;
	unsigned int	temp;

	*num_digits = 0;
	temp = u;
	if (u == 0)
		*num_digits = 1;
	while (temp != 0)
	{
		(*num_digits)++;
		temp /= 10;
	}
	ret = ft_calloc(1, *num_digits + 1);
	return (ret);
}
