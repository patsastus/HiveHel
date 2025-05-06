/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:22:37 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/01 09:58:52 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libftprintf.h"
#include "tests.h"


int main(void)
{
	int clib;
	int	ft;
	printf("Testing functionality  ft_printf, by comparison to clib printf\n");

//simple string	without any conversion
	clib = printf("cl:\t\n");
	ft = ft_printf("ft:\t\n");
	printf("Returns: %d | %d \n", clib, ft);
//one percent sign
	clib = printf("cl:\t%%\n");
	ft = ft_printf("ft:\t%%\n");
	printf("Returns: %d | %d \n", clib, ft);

	test_chars(32, 64);

	test_strs();
	
	test_ptrs();

	test_ints();

	test_uints();

	test_hexes();

	test_basic();
	
	return (0);
}
