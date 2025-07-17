/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:30:51 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/17 11:09:17 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			counter;
	unsigned char	*d;

	if (n == 0)
		return (dest);
	d = (unsigned char *)dest;
	counter = n - 1;
	if (dest > src)
	{
		while (counter > 0)
		{
			d[counter] = ((unsigned char *)src)[counter];
			counter--;
		}
		d[counter] = ((unsigned char *)src)[counter];
		return (dest);
	}
	counter = 0;
	while (counter < n)
	{
		d[counter] = ((unsigned char *)src)[counter];
		counter++;
	}
	return (dest);
}
