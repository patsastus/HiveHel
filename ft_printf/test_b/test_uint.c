/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:55:29 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/08 12:39:22 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"

static char	*add_flag(const char *s, char c);

void	test_uints(void)
{
	char			*flags = "0-";
	unsigned long	input[6] = {0, 1, 42, INT_MAX, UINT_MAX, ULONG_MAX};
	char			*tests[7] = {"|%u|\n", "|%5u|\n", "|%3.5u|\n", "|%8.11u|\n", "|%11.8u|\n", "|%20.10u|\n", "|%10.20u|\n"};
	int				i = 0;
	int 			j;
	int				k;
	int				cl;
	int				ft;
	char			*temp;

	printf("\nTesting unsigned integer outputs, at different widths/precision and different combos of flags %s\n", flags);
	while (i < 6)
	{
		ft_printf("Input: %d\n", input[i]);
		j = 0;
		while (j < 7)
		{
			k = 0;
			printf("format string:'%s'\n", tests[j]);
			while ((size_t)k < ft_strlen(flags) + 1)
			{
				if (k == 0)
					temp = ft_strdup(tests[j]);
				else
					temp = add_flag(tests[j], flags[k - 1]);
				cl = printf(temp, input[i]);
				ft = ft_printf(temp, input[i]);
				printf("Returns: %d | %d\n", cl, ft);
				free(temp);
				k++;
			}
			j++;
		}
    	i++;
	}
	return ;
}

static char	*add_flag(const char *s, char c)
{
	char	*ret;
	
	ret = ft_calloc(ft_strlen(s) + 2, 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, 3);
	ret[2] = c;
	ft_strlcat(ret, s + 2, ft_strlen(s) + 2);
	return (ret);
}
