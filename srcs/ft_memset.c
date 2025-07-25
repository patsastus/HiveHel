/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:14:24 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/16 10:49:05 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*temp;

	counter = 0;
	temp = (unsigned char *)s;
	while (counter < n)
	{
		temp[counter] = (unsigned char)c;
		counter++;
	}
	return (s);
}
