/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:04:24 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/30 12:39:02 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libftprintf.h"
#include "tests.h"

void	test_strs(void)
{
	int clib;
	int	ft;

	printf("Testing flag '%%s' with some test inputs:\n");
	//one string
	clib = printf("cl:\t%s\n", "test");
	ft = ft_printf("ft:\t%s\n", "test");
	printf("Returns: %d | %d \n", clib, ft);
	//NULL
	clib = printf("cl:\t%s\n", (char *)NULL);
	ft = ft_printf("ft:\t%s\n", (char *)NULL);
	printf("Returns: %d | %d \n", clib, ft);
}
