/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:28:02 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/06 09:41:23 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
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
		prefixed = ft_strjoin("0x", temp);
	}
	ret = write(1, prefixed, ft_strlen(prefixed));
	free(temp);
	free(prefixed);
	return (ret);
}
