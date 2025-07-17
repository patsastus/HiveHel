/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:26:19 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/19 15:08:57 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*	
*	returns the index of the first newline found starting at index start, or 
*	-1 if no newline found before index buf
*/
ssize_t	i_of_newline(char *s, ssize_t start, ssize_t buf)
{
	ssize_t	i;

	i = start;
	while (i < buf)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *one, char *two, ssize_t len)
{
	char	*ret;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(one);
	if (len == 0)
		len2 = ft_strlen(two);
	else
		len2 = len;
	ret = malloc(len1 + len2 + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i++ < len1)
		ret[i - 1] = one[i - 1];
	i = 0;
	while (i++ < len2)
		ret[len1 + i - 1] = two[i - 1];
	ret[len1 + len2] = '\0';
	return (ret);
}

ssize_t	ft_strlen(char *s)
{
	ssize_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
