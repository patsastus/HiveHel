/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:21:01 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/09 10:57:29 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf_bonus.h"
#include "../libft/libft.h"

int	write_char_bonus(char c, t_flag *flags)
{
	char	*temp;
	int		ret;

	if (flags->width > 1)
	{
		temp = pad_c(c, flags);
		if (!temp)
			return (0);
		ret = write(1, temp, ft_strlen(temp));
		free(temp);
		if (c == '\0')
		{
			ret += write(1, "", 1);
			if (flags->minus)
			{
				while (ret < flags->width)
					ret += write(1, " ", 1);
			}
		}
		return (ret);
	}
	return (write(1, &c, 1));
}
