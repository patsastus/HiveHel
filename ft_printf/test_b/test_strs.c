/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:12:01 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/08 12:39:26 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"

void	test_strs(void)
{
	const char	*tests[6] = {"|%s|\n", "|%2s|\n", "|%-2s|\n",  "|%7.2s|\n",  "|%-8.3s|\n", "|%6.8s|\n"};
	const char	*input[3] = {"", "testing", NULL};
	int			i;
	int			j;
	int			cl;
	int			ft;
	
	j = 0;
	while (j < 3)
	{
		i = 0;
		printf("\ntesting input string: ");
		printf("'%s'\n", input[j]);
		while (i < 6)
		{
			printf("format string:\n");
			ft_putendl_fd((char *)tests[i], 1);
			cl = printf(tests[i], input[j]);
			ft = ft_printf(tests[i], input[j]);
			printf("Returns; %d | %d\n", cl, ft);
			i++;
		}
		j++;
	}
}
