/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:49:48 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/21 15:04:06 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(s);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (ret);
	*ret = '\0';
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}
