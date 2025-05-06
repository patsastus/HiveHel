/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:06:12 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/29 15:53:50 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include "libft/libft.h"

int	write_str(char *s)
{
	char	*catch;
	int		ret;

	if (s)
		return (write(1, s, ft_strlen(s)));
	catch = ft_strdup("(null)");
	ret = write(1, catch, ft_strlen(catch));
	free(catch);
	return (ret);
}
