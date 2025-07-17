/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bucket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:29:37 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/01 11:40:05 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	make_cutoffs(int **ptr, t_list *stack)
{
	int	arr_size;
	int	lst_size;
	int	i;

	lst_size = ft_lstsize(stack);
	arr_size = lst_size / BUCKET_SIZE;
	if (lst_size > 200)
		arr_size = lst_size / (BUCKET_SIZE * 2);
	*ptr = malloc(sizeof(int) * arr_size);
	if (!(*ptr))
		free_and_exit(NULL);
	i = 0;
	while (i < arr_size)
	{
		(*ptr)[arr_size - 1 - i] = get_median(stack, i, arr_size);
		i++;
	}
	return (arr_size);
}

static void	push_to_b(t_data *data, int min, int max)
{
	int	count;

	count = 0;
	while (*(int *)data->a->content <= max && count <= data->stack_size + 1)
	{
		if (*(int *)data->a->content > min && *(int *)data->a->content <= max)
			make_move(data, PUSHB);
		else
			make_move(data, ROTA);
		++count;
	}
}

static int	shorter_rotate(t_list *list, int min, int size)
{
	int	distances[2];

	distances[0] = 0;
	distances[1] = 0;
	while (*(int *)list->content > min)
	{
		list = list->next;
		distances[0]++;
	}
	distances[1] = distances[0];
	while (list && *(int *)list->content <= min)
	{
		list = list->next;
		distances[1]++;
	}
	if (distances[0] < size - distances[1])
		return (0);
	else
		return (1);
}

static void	sort_from_b(t_data *data, int min)
{
	int	minmax[3];
	int	costs[3];

	minmax[2] = list_min(data->b);
	while (data->size_b > 0)
	{
		minmax[0] = list_min(data->b);
		minmax[1] = list_max(data->b);
		costs[0] = calculate_cost(data, 0, index_of(data->b, minmax[0]));
		costs[1] = calculate_cost(data, 0, index_of(data->b, minmax[1]));
		if (costs[1] <= costs[0])
			move_to_a(data, 0, minmax[1]);
		else
		{
			move_to_a(data, 0, minmax[0]);
			make_move(data, ROTA);
		}
	}
	costs[2] = shorter_rotate(data->a, min, data->stack_size);
	final_rotate(data, list_max(data->a));
	make_move(data, ROTA);
}

void	sort_bucket(t_data *data)
{
	int		*cutoffs;
	int		index;
	int		size;

	if (data->stack_size <= 10)
	{
		presort(data);
		small_sort(data);
		return ;
	}
	size = make_cutoffs(&cutoffs, data->a);
	index = 1;
	push_to_b(data, cutoffs[0], INT_MAX);
	sort_from_b(data, cutoffs[0]);
	while (index < size)
	{
		push_to_b(data, cutoffs[index], cutoffs[index - 1]);
		sort_from_b(data, cutoffs[index]);
		index++;
	}
	push_to_b(data, INT_MIN, cutoffs[index - 1]);
	sort_from_b(data, cutoffs[index - 1]);
	free(cutoffs);
}
