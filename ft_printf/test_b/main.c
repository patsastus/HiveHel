/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:35:03 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/09 10:43:43 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../bonus/libftprintf_bonus.h"
#include <stdio.h>
#include "tests.h"
int	main(void)
{
	test_chars();

    test_strs(); 
                 
    test_ptrs(); 
                 
    test_ints(); 
                 
    test_uints();
                 
    test_hexes();

	return (0);
}


