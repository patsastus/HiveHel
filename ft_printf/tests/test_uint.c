/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:29:17 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/30 12:41:55 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libftprintf.h"
#include "tests.h"

void	test_uints(void)
{
	unsigned int	tests[5] = {0, 1, 2, 42, UINT_MAX};
	int				i = 0;
	int				clib;
	int				ft;

	printf("Testing flags '%%u' with some test inputs:\n");
	while (i < 5)
	{
		clib = printf("cl:\t%u\n", tests[i]);
		ft = ft_printf("ft:\t%u\n", tests[i]);
		printf("Returns: %d | %d \n", clib, ft);
		i++;
	}
	clib = printf("cl:\t%u %u %u %u %u\n", tests[0], tests[1], tests[2], tests[3], tests[4]);
	ft = ft_printf("ft:\t%u %u %u %u %u\n", tests[0], tests[1], tests[2], tests[3], tests[4]);
	printf("Returns: %d | %d \n", clib, ft);
}
