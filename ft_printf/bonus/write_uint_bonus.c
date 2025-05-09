/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:04:01 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/09 10:41:07 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"
#include "../libft/libft.h"

static void	handle_flags(char **s, t_flag *flags);

int	write_uint_bonus(unsigned int u, t_flag *flags)
{
	char	*temp;
	int		ret;

	temp = ft_utoa(u);
	if (flags->prec && !(flags->precision) && !u)
	{
		free(temp);
		temp = ft_strdup("");
	}
	handle_flags(&temp, flags);
	ret = (write(1, temp, ft_strlen(temp)));
	free(temp);
	return (ret);
}

static void	handle_flags(char **s, t_flag *flags)
{
	char	*temp;
	int		zeros;

	zeros = flags->precision - ft_strlen(*s);
	if (zeros > 0)
	{
		temp = pad_zero(*s, zeros);
		free(*s);
		*s = temp;
	}
	if ((size_t)(flags->width) > ft_strlen(*s))
	{
		if (flags->zero && !(flags->prec))
			temp = pad_zero(*s, flags->width - ft_strlen(*s));
		else
			temp = pad_s(*s, flags, ft_strlen(*s));
		free(*s);
		*s = temp;
	}
}
