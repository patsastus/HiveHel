/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:29:37 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/02 15:55:28 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	presort(t_data *data)
{
	float	mean;
	int		count;

	if (data->size_a < 2)
		return ;
	mean = 0.0;
	count = 0;
	while (data->size_a > 3)
	{
		mean = (mean * count + *(int *)(data->a->content)) / count;
		++count;
		make_move(data, PUSHB);
		if (*(int *)(data->b->content) > mean && ft_lstsize(data->b) > 1)
			make_move(data, ROTB);
	}
	small_sort(data);
}

void	small_sort(t_data *data)
{
	int	values[3];

	if (data->size_a == 3)
	{
		values[0] = *(int *)(data->a->content);
		values[1] = *(int *)(data->a->next->content);
		values[2] = *(int *)(data->a->next->next->content);
		if (values[0] > values[1] && values[0] > values[2])
			make_move(data, ROTA);
		if (values[1] > values[0] && values[1] > values[2])
			make_move(data, RROTA);
	}
	if (*(int *)(data->a->next->content) < *(int *)(data->a->content))
		make_move(data, SWAPA);
	while (!is_sorted(data))
	{
		if (data->size_a == data->stack_size)
		{
			final_rotate(data, list_min(data->a));
			break ;
		}
		find_best_candidate(data);
	}
}

void	move_to_a(t_data *data, int a_i, int value_b)
{
	int	b_i;
	int	index;

	b_i = index_of(data->b, value_b);
	calculate_cost(data, a_i, b_i);
	index = 0;
	if (data->candidate == 1)
		move_rotate_both(data, a_i, b_i);
	if (data->candidate == 2)
		move_rev_rotate_both(data, a_i, b_i);
	if (data->candidate == 3)
		move_opposite_rotate_both(data, a_i, b_i);
	make_move(data, PUSHA);
}

/*
	returns from the whole list the smallest element that's larger than the
	value of node, and smaller than the value of check, if it exists.
	returns LONG_MIN if no legal node was found.
*/
long	largest_below(t_list *list, t_list *node, t_list *check)
{
	long	temp;
	int		list_val;
	int		node_val;

	temp = LONG_MIN;
	node_val = *(int *)(node->content);
	if (check != NULL && (long)*(int *)check->content < node_val)
		temp = (long)*(int *)check->content;
	while (list != NULL)
	{
		list_val = *(int *)(list->content);
		if (list_val < node_val && list_val > temp)
			temp = list_val;
		list = list->next;
	}
	if (check && temp == (long)*(int *)check->content)
		return (LONG_MIN);
	return (temp);
}

/*
	returns from the whole list the smallest element that's larger than the
	value of node, and smaller than the value of check, if it exists.
	returns LONG_MAX if no legal node was found. 
*/
long	smallest_above(t_list *list, t_list *node, t_list *check)
{
	long	temp;
	int		list_val;
	int		node_val;

	temp = LONG_MAX;
	if (!check)
		return (temp);
	node_val = *(int *)(node->content);
	if ((long)*(int *)check->content > node_val)
		temp = (long)*(int *)check->content;
	while (list != NULL)
	{
		list_val = *(int *)(list->content);
		if (list_val > node_val && list_val < temp)
			temp = list_val;
		list = list->next;
	}
	if (check && temp == (long)*(int *)check->content)
		return (LONG_MAX);
	return (temp);
}
