/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:33:39 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/30 13:31:40 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

static void	to_upper(unsigned int u, char *s);

int	write_hex(int i, int upper)
{
	char	*temp;
	int		ret;

	temp = ft_itoa_hex((unsigned int)i);
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
