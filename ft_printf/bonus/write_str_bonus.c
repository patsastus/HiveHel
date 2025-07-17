/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:06:12 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:48:16 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "../libft/libft.h"

static void	handle_flags(char **s, t_flag *flags);

int	write_str_bonus(char *s, t_flag *flags)
{
	char	*catch;
	int		ret;

	if (!s)
	{
		if (flags->precision && flags->precision_value < 6)
			catch = ft_strdup("");
		else
			catch = ft_strdup("(null)");
	}
	else if (flags->precision)
		catch = ft_substr(s, 0, flags->precision_value);
	else
		catch = ft_strdup(s);
	if (!catch)
		return (-1);
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
	if (flags->precision && flags->precision_value < len)
	{
		len = flags->precision_value;
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
