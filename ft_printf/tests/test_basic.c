/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:13:35 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/30 12:49:26 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libftprintf.h"
#include "tests.h"

void	test_basic(void)
{
	int				c = 42;
	unsigned int	u = 84;
	void			*ptr = test_basic;
	unsigned int	hex = 32567;
	unsigned int	max = UINT_MAX;
	int				clib;
	int				ft;

	clib = printf("%c%s%p%d%i%u%x%X%%\n", 'f', " test ", ptr, c, c/2, u, hex, max);
	ft = ft_printf("%c%s%p%d%i%u%x%X%%\n", 'f', " test ", ptr, c, c/2, u, hex, max);
	printf("Returns: %d | %d \n", clib, ft);
}
