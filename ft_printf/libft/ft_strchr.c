/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:12:46 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/24 14:06:08 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (*ret != '\0')
	{
		if ((unsigned char)*ret == (unsigned char)c)
			return (ret);
		ret++;
	}
	if (c == '\0')
		return (ret);
	return (NULL);
}
