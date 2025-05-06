/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:00:09 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/30 12:38:40 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libftprintf.h"
#include "tests.h"

void	test_chars(int min, int max)
{
	int clib;
	int	ft;
	int	i;

	printf("Testing flag '%%c' with input 'c':\n");
	//one char passed as argument
	clib = printf("cl:\t%c\n", 'c');
	ft = ft_printf("ft:\t%c\n", 'c');
	printf("Returns: %d | %d \n", clib, ft);
	i = min;
	printf("Testing flag '%%c' with inputs ranging from %d to %d:\n", min, max);
	while (i < max)
	{
		clib = printf("cl:\t%c\n", i);
		ft = ft_printf("ft:\t%c\n", i);
		printf("Returns: %d | %d \n", clib, ft);
		i++;
	}
}

