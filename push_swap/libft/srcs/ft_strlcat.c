/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:53:02 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/25 10:11:17 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	length_d;
	size_t	length_s;

	if (size == 0)
		return (ft_strlen(src));
	length_d = ft_strlen(dest);
	length_s = ft_strlen(src);
	if (length_d >= size)
		length_d = size;
	if (length_d == size)
		return (length_d + length_s);
	if (length_d + length_s < size)
		ft_memcpy(dest + length_d, src, length_s + 1);
	else
	{
		if (size - length_d >= 1)
			ft_memcpy(dest + length_d, src, size - length_d - 1);
		dest[size - 1] = '\0';
	}
	return (length_d + length_s);
}
