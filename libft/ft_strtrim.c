/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:49:54 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/19 14:48:18 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			size;
	size_t			i;

	start = 0;
	i = 0;
	while (i < ft_strlen(s1) && is_in_set(s1[i], set))
	{
		start++;
		i++;
	}
	size = ft_strlen(s1);
	i = size - 1;
	while (i >= 0 && is_in_set(s1[i], set))
	{
		size--;
		i--;
	}
	return (ft_substr(s1, start, size - start));
}

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
