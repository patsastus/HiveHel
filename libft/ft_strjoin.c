/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:23:30 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/23 14:31:16 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	temp;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(size);
	if (ret == NULL)
		return (ret);
	*ret = '\0';
	temp = ft_strlcat(ret, s1, size);
	temp = ft_strlcat(ret, s2, size);
	return (ret);
}
