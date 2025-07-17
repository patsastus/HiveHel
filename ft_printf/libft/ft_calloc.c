/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:27:02 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/25 10:09:31 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (size > 0 && nmemb > INT_MAX / size)
		return (NULL);
	if (!nmemb || !size)
		return (malloc(0));
	ret = malloc(nmemb * size);
	if (ret == NULL)
		return (ret);
	ret = ft_bzero(ret, nmemb * size);
	return (ret);
}
