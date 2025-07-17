/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:21:01 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 12:20:46 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "../libft/libft.h"

int	write_char_bonus(char c, t_flag *flags)
{
	char	*temp;
	int		ret;
	int		flag;

	flag = 0;
	if (flags->width > 1)
	{
		temp = pad_c(c, flags);
		if (!temp)
			return (0);
		if (c == '\0' && flags->minus)
			flag = write(1, "", 1);
		if (flag == -1)
			return (-1);
		ret = write(1, temp + flag, ft_strlen(temp + flag));
		if (c == '\0' && !(flags->minus))
			flag = write(1, "", 1);
		if (flag == -1)
			return (-1);
		free(temp);
		return (ret + flag);
	}
	return (write(1, &c, 1));
}
