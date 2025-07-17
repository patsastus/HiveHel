/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:34:24 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/24 15:11:40 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	temp;
	char	*ret;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	ret = malloc(size + 1);
	if (ret == NULL)
		return (ret);
	*ret = '\0';
	temp = ft_strlcpy(ret, s + start, size + 1);
	return (ret);
}
