/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:28:02 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/09 11:00:07 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf_bonus.h"
#include "../libft/libft.h"

static void	handle_flags(char **s, t_flag *flags);
static void	add_zeros(char **s, int n);

int	write_ptr_bonus(void *p, t_flag *flags)
{
	char	*temp;
	char	*prefixed;
	int		ret;

	if (!p)
	{
		temp = ft_strdup("");
		prefixed = ft_strdup("(nil)");
	}
	else
	{
		temp = ft_itoa_hex((unsigned long)p);
		if (ft_strlen(temp) < (size_t)flags->precision)
			add_zeros(&temp, flags->precision - ft_strlen(temp));
		prefixed = ft_strjoin("0x", temp);
	}
	if (ft_strlen(prefixed) < (size_t)flags->width)
		handle_flags(&prefixed, flags);
	if (!prefixed)
		return (0);
	ret = write(1, prefixed, ft_strlen(prefixed));
	free(temp);
	free(prefixed);
	return (ret);
}

static void	handle_flags(char **s, t_flag *flags)
{
	char	*temp;

	if ((size_t)flags->width > ft_strlen(*s))
	{
		temp = pad_s(*s, flags, ft_strlen(*s));
		free(*s);
		*s = temp;
	}
}

static void	add_zeros(char **s, int n)
{
	char	*temp;

	temp = pad_zero(*s, n);
	if (temp)
	{
		free(*s);
		*s = temp;
	}
}
