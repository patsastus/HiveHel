/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ptrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:06:12 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/30 13:34:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libftprintf.h"
#include "tests.h"

void	test_ptrs(void)
{
	int 	clib;
	int		ft;
	char	*temp;

	printf("Testing flag '%%p' with some test pointers:\n");
//one NULL pointer
	clib = printf("cl:\t%p\n", NULL);
	ft = ft_printf("ft:\t%p\n", NULL);
	printf("Returns: %d | %d \n", clib, ft);
//one stack pointer
	clib = printf("cl:\t%p\n", &test_ptrs);
	ft = ft_printf("ft:\t%p\n", &test_ptrs);
	printf("Returns: %d | %d \n", clib, ft);

	int c = 42;
	temp = strdup("testing");
	//three, including maximum? possible value
	clib = printf("cl:\t%p %p %p\n", &c, temp, (void *)ULONG_MAX);
	ft = ft_printf("ft:\t%p %p %p\n", &c, temp, (void *)ULONG_MAX);
	printf("Returns: %d | %d \n", clib, ft);

	free(temp);
}
