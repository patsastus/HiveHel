/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:06:12 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/09 09:43:14 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf_bonus.h"
#include "../libft/libft.h"

static void	handle_flags(char **s, t_flag *flags);

int	write_str_bonus(char *s, t_flag *flags)
{
	char	*catch;
	int		ret;

	if (!s)
	{
		if (flags->prec && flags->precision < 6)
			catch = ft_strdup("");
		else
			catch = ft_strdup("(null)");
	}
	else if (flags->prec)
		catch = ft_substr(s, 0, flags->precision);
	else
		catch = ft_strdup(s);
	handle_flags(&catch, flags);
	if (!catch)
		return (-1);
	ret = write(1, catch, ft_strlen(catch));
	free(catch);
	return (ret);
}

static void	handle_flags(char **s, t_flag *flags)
{
	int		len;
	char	*temp;

	len = ft_strlen(*s);
	if (flags->prec && flags->precision < len)
	{
		len = flags->precision;
		temp = ft_substr(*s, 0, len);
		free(*s);
		*s = temp;
	}
	if (flags->width > len)
	{
		temp = pad_s(*s, flags, len);
		free(*s);
		*s = temp;
	}
}
