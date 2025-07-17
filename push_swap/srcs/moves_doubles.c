/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:33:12 by nraatika          #+#    #+#             */
/*   Updated: 2025/06/18 17:06:03 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_both(void *ptr)
{
	rotate_a(ptr);
	rotate_b(ptr);
	return ;
}

void	rev_rotate_both(void *ptr)
{
	rev_rotate_a(ptr);
	rev_rotate_b(ptr);
	return ;
}

void	swap_both(void *ptr)
{
	swap_a(ptr);
	swap_b(ptr);
	return ;
}
