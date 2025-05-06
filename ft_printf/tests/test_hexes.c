/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hexes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:37:47 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/30 13:31:59 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libftprintf.h"
#include "tests.h"

void	test_hexes(void)
{
	unsigned int tests[] = {0, 42, INT_MAX, UINT_MAX};
	int i = 0;
	int clib;
	int ft;

	printf("\nTesting flag '%%x' and '%%x' with some test pointers:\n");
	while (i < 4)
	{
		clib = printf("cl:\t%x\n", tests[i]);
		ft = ft_printf("ft:\t%x\n", tests[i]);
		printf("Returns: %d | %d \n", clib, ft);
		clib = printf("cl:\t%X\n", tests[i]);
		ft = ft_printf("ft:\t%X\n", tests[i]);
		printf("Returns: %d | %d \n", clib, ft);
		i++;
	}

	clib = printf("cl:\t%x\n", -10);
	ft = ft_printf("ft:\t%x\n", -10);
	printf("Returns: %d | %d \n", clib, ft);

}
