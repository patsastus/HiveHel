/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:32:42 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/08 12:38:51 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"

static char	*add_flag(const char *s, char c);

void	test_ints(void)
{
	char	*flags = "0-+ ";
	long	input[7] = {0, -1, 42, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN};
	char	*tests[7] = {"|%d|\n", "|%5i|\n", "|%3.5d|\n", "|%8.11i|\n", "|%11.8d|\n", "|%20.10i|\n", "|%10.20d|\n"};
	int		i = 0;
	int 	j;
	int		k;
	int		cl;
	int		ft;
	char	*temp;

	printf("\nTesting integer outputs, at different widths/precision and different combos of flags %s\n", flags);
	while (i < 7)
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
