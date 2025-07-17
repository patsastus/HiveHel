/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:46:38 by nraatika          #+#    #+#             */
/*   Updated: 2025/06/30 11:41:32 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
	calculates the cost of moving the element at b_i into index a_i
	the cost is one of three options:
	1. rotate both stacks, cost is the larger of the indexes
	2. reverse rotate both stacks, cost is 
		the larger of size_a - a_i, size_b - b_i
	3. the smaller of a_i + size_b - b_i and
					 b_i + size_a - a_i
*/
int	calculate_cost(t_data *data, int a_i, int b_i)
{
	int	candidates[3];

	candidates[0] = ft_max(a_i, b_i);
	candidates[1] = ft_max(data->size_a - a_i, data->size_b - b_i);
	candidates[2] = ft_min(a_i + data->size_b - b_i, b_i + data->size_a - a_i);
	if (candidates[0] < candidates[1] && candidates[0] < candidates[2])
	{
		data->candidate = 1;
		return (candidates[0]);
	}
	if (candidates[1] < candidates[2])
	{
		data->candidate = 2;
		return (candidates[1]);
	}
	data->candidate = 3;
	return (candidates[2]);
}

/*
	Rotate both stacks, a a_i times and b b_i times
*/
void	move_rotate_both(t_data *data, int a_i, int b_i)
{
	int	index;

	index = 0;
	while (index < ft_min(a_i, b_i))
	{
		make_move(data, RR);
		++index;
	}
	while (index < ft_max(a_i, b_i))
	{
		if (a_i > b_i)
			make_move(data, ROTA);
		else
			make_move(data, ROTB);
		++index;
	}
}

/*
	Reverse rotate both stacks, a size_a - a_i times and b size_b - b_i times
*/
void	move_rev_rotate_both(t_data *data, int a_i, int b_i)
{
	int	index;

	index = 0;
	while (index < ft_min(data->size_a - a_i, data->size_b - b_i))
	{
		make_move(data, RRR);
		++index;
	}
	while (index < ft_max(data->size_a - a_i, data->size_b - b_i))
	{
		if (data->size_a - a_i > data->size_b - b_i)
			make_move(data, RROTA);
		else
			make_move(data, RROTB);
		++index;
	}
}

/*
	Rotate stacks in opposite directions, a a_i times and b b_i times
	Direction is determined by lesser combined cost
*/
void	move_opposite_rotate_both(t_data *data, int a_i, int b_i)
{
	int	index;

	index = 0;
	if (a_i + data->size_b - b_i < b_i + data->size_a - a_i)
	{
		while (index++ < a_i)
			make_move(data, ROTA);
		index = 0;
		while (index++ < data->size_b - b_i)
			make_move(data, RROTB);
	}
	else
	{
		while (index++ < b_i)
			make_move(data, ROTB);
		index = 0;
		while (index++ < data->size_a - a_i)
			make_move(data, RROTA);
	}
}

void	final_rotate(t_data *data, int pivot)
{
	int	index;
	int	count;

	index = index_of(data->a, pivot);
	count = 0;
	if (index < data->stack_size - index)
	{
		while (count < index)
		{
			make_move(data, ROTA);
			++count;
		}
	}
	else
	{
		while (count < data->stack_size - index)
		{
			make_move(data, RROTA);
			++count;
		}
	}
}
