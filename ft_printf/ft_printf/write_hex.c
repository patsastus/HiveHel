/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:33:39 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:56:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	to_upper(unsigned int u, char *s);

int	write_hex(int i, int upper)
{
	char	*temp;
	int		ret;

	temp = ft_itoa_hex((unsigned int)i);
	if (!temp)
		return (-1);
	if (upper)
		ft_striteri(temp, to_upper);
	ret = write(1, temp, ft_strlen(temp));
	free(temp);
	return (ret);
}

static void	to_upper(unsigned int u, char *s)
{
	u = 1;
	*s = ft_toupper(*s);
}
