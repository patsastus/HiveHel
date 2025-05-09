/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:37:12 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/08 12:26:08 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_chars(void)
{
	const char	*tests[5] = {"|%c|\n", "|%2c|\n", "|%-2c|\n", "|%4c|\n", "|%-4c|\n"};
	int			i;
	int			cl;
	int			ft;
	
	ft_printf("\nTesting char with different widths and '-' flag\n");
	i = 0;
	while (i < 5)
	{
		cl = printf(tests[i], 'f');
		ft = ft_printf(tests[i], 'f');
		printf("Returns; %d | %d\n", cl, ft);
		i++;
	}
}
