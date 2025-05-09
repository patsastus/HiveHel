/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hexes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:35:04 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/08 12:29:03 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static char	*add_flag(const char *s, char c);

void	test_hexes(void)
{
	char			*flags = "0-#";
	long			input[7] = {0, -11, 42, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN};
	char			*test_lo[7] = {"|%x|\n", "|%5x|\n", "|%3.5x|\n", "|%8.11x|\n", "|%11.8x|\n", "|%20.10x|\n", "|%10.20x|\n"};
	char			*test_hi[7] = {"|%X|\n", "|%5X|\n", "|%3.5X|\n", "|%8.11X|\n", "|%11.8X|\n", "|%20.10X|\n", "|%10.20X|\n"};
	int				i = 0;
	int 			j;
	int				k;
	int				ft;
	int				cl;
	char			*temp;

	printf("\nTesting hexadecimal outputs, at different widths/precision and different combos of flags %s\n", flags);
	while (i < 6)
	{
		ft_printf("Input: %d\n", input[i]);
		j = 0;
		while (j < 7)
		{
			k = 0;
			while ((size_t)k < ft_strlen(flags) + 1)
			{
				if (k == 0)
					temp = ft_strdup(test_lo[j]);
				else
					temp = add_flag(test_lo[j], flags[k - 1]);
				cl = printf(temp, input[i]);
				ft = ft_printf(temp, input[i]);
				printf("Returns: %d | %d\n", cl, ft);
				free(temp);
				if (k == 0)
					temp = ft_strdup(test_hi[j]);
				else
					temp = add_flag(test_hi[j], flags[k - 1]);
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
