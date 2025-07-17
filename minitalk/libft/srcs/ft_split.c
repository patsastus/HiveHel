/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:25:11 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/23 15:45:52 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

static int		count_words(char const *s, char c);
static size_t	mod_strlen(char const *s, char c);
static char		**free_all(char **ret, size_t size);

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	size;
	size_t	i;

	size = count_words(s, c);
	ret = malloc((size + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			ret[i] = ft_substr(s, 0, mod_strlen(s, c));
			if (ret[i] == NULL)
				return (free_all(ret, i));
			s += mod_strlen(s, c);
			i++;
		}
		if (*s)
			s++;
	}
	ret[i] = NULL;
	return (ret);
}

static int	count_words(char const *s, char c)
{
	int	word;
	int	count;

	word = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (word)
			{
				count++;
				word = 0;
			}
		}
		else
		{
			if (!word)
				word = 1;
		}
		s++;
	}
	return (count + word);
}

static size_t	mod_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_all(char **ret, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}
