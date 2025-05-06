/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:22:48 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/24 14:07:36 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			ret = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (ret);
}
