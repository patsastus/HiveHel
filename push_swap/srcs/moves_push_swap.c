/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:39:18 by nraatika          #+#    #+#             */
/*   Updated: 2025/06/18 17:13:45 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_a(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (data->size_a < 2)
		return ;
	swap_top_two(&(data->a));
	return ;
}

void	swap_b(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (data->size_b < 2)
		return ;
	swap_top_two(&(data->b));
	return ;
}

void	push_a(void *ptr)
{
	t_list	*temp;
	t_data	*data;

	data = (t_data *)ptr;
	if (data->size_b == 0)
		return ;
	temp = data->b;
	data->b = data->b->next;
	ft_lstadd_front(&(data->a), temp);
	(data->size_b)--;
	(data->size_a)++;
}

void	push_b(void *ptr)
{
	t_list	*temp;
	t_data	*data;

	data = (t_data *)ptr;
	if (data->size_a == 0)
		return ;
	temp = data->a;
	data->a = data->a->next;
	ft_lstadd_front(&(data->b), temp);
	(data->size_a)--;
	(data->size_b)++;
}
