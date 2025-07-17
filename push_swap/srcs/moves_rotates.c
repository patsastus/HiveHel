/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:49:19 by nraatika          #+#    #+#             */
/*   Updated: 2025/06/18 17:05:33 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_a(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (data->size_a < 2)
		return ;
	rotate_list(&(data->a));
	return ;
}

void	rotate_b(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (data->size_b < 2)
		return ;
	rotate_list(&(data->b));
	return ;
}

void	rev_rotate_a(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (data->size_a < 2)
		return ;
	rev_rotate_list(&(data->a));
	return ;
}

void	rev_rotate_b(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (data->size_b < 2)
		return ;
	rev_rotate_list(&(data->b));
	return ;
}
