/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:36:10 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/16 11:15:31 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	void	*ret;

	index = 0;
	ret = (void *)s;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char)c)
		{
			return (ret + index);
		}
		index++;
	}
	return (NULL);
}
