/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:34:15 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/30 12:40:48 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libftprintf.h"
#include "tests.h"

void	test_ints(void)
{
	int		tests[5] = {INT_MAX, INT_MIN, 0, -42, 42};

	printf("Testing flags '%%d' and '%%i' with some test inputs:\n");
	int i = 0;
	int clib;
	int ft;
	while (i < 5)
	{
		clib = printf("cl:\t%d\n", tests[i]);
		ft = ft_printf("ft:\t%d\n", tests[i]);
		printf("Returns: %d | %d \n", clib, ft);
		clib = printf("cl:\t%i\n", tests[i]);
		ft = ft_printf("ft:\t%i\n", tests[i]);
		printf("Returns: %d | %d \n", clib, ft);
		i++;
	}
	clib = printf("cl:\t%d %d %i %i %d\n", tests[0], tests[1], tests[2], tests[3], tests[4]);
	ft = ft_printf("ft:\t%d %d %i %i %d\n", tests[0], tests[1], tests[2], tests[3], tests[4]);
	printf("Returns: %d | %d \n", clib, ft);
}
