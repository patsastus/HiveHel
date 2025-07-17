/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:26:32 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/16 11:16:06 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			counter;
	unsigned char	*d;

	counter = 0;
	d = (unsigned char *)dest;
	while (counter < n)
	{
		d[counter] = ((unsigned char *)src)[counter];
		counter++;
	}
	return (dest);
}
