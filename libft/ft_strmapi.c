/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:58:25 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/19 14:46:44 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	ret = ft_strdup(s);
	if (ret == NULL)
		return (ret);
	i = 0;
	while (i < ft_strlen(s))
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
