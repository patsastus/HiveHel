/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:06:12 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:56:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

int	write_str(char *s)
{
	char	*catch;
	int		ret;

	if (s)
		return (write(1, s, ft_strlen(s)));
	catch = ft_strdup("(null)");
	if (!catch)
		return (-1);
	ret = write(1, catch, ft_strlen(catch));
	free(catch);
	return (ret);
}
