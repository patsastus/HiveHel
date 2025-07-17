/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:28:02 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:56:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

int	write_ptr(void *p)
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
		if (!temp)
			return (-1);
		prefixed = ft_strjoin("0x", temp);
	}
	if (!prefixed)
	{
		free(temp);
		return (-1);
	}
	ret = write(1, prefixed, ft_strlen(prefixed));
	free(temp);
	free(prefixed);
	return (ret);
}
