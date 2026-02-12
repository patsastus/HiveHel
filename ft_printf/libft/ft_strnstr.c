/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:20:22 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/16 11:28:45 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	in;
	size_t	out;
	size_t	lit;
	char	*ret;

	ret = (char *)big;
	if (!*little)
		return (ret);
	lit = ft_strlen(little);
	in = 0;
	out = 0;
	while (ret[out] && out + lit <= len)
	{
		while (in < lit && ret[out + in] && little[in] == ret[out + in])
			in++;
		if (in == lit)
			return (ret + out);
		else
			in = 0;
		out++;
	}
	return (NULL);
}
