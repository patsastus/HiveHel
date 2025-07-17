/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:09:53 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/02 15:55:14 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	write_move(t_move move)
{
	const char *const	moves[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb"\
		, "rr", "rra", "rrb", "rrr"};
	const char			*temp;

	temp = moves[move];
	write(1, temp, ft_strlen(temp));
	write(1, "\n", 1);
}

void	make_move(t_data *data, t_move m)
{
	data->funcs[m]((void *)data);
	write_move(m);
}

int	is_sorted(t_data *data)
{
	t_list	*tmp;

	if (ft_lstsize(data->a) < data->stack_size)
		return (0);
	tmp = data->a;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	find_best_candidate(t_data *data)
{
	long	*tmp;
	t_list	*sorted[3];
	int		i;

	if (data->size_b == 0)
		return ;
	tmp = malloc(sizeof(long) * 2 * data->size_a);
	if (!tmp)
		free_and_exit(NULL);
	i = 0;
	sorted[0] = ft_lstlast(data->a);
	sorted[1] = data->a;
	if (*(int *)sorted[0]->content >= *(int *)sorted[1]->content)
		sorted[0] = NULL;
	while (sorted[1] != NULL)
	{
		sorted[2] = sorted[1]->next;
		tmp[i * 2] = largest_below(data->b, sorted[1], sorted[0]);
		tmp[i * 2 + 1] = smallest_above(data->b, sorted[1], sorted[2]);
		sorted[0] = sorted[1];
		sorted[1] = sorted[2];
		++i;
	}
	choose_and_make_moves(data, tmp);
	free(tmp);
}

/*
	arguments:data structure and an array of longs, containing possible 
	candidates to move. for each member of array that's in integer range, 
	calculate the cost to make the move:
	at index i of the array, the corresponding index in stack a is
	a_i = i/2;
	the index of the candidate in stack b is
	b_i = index_of(data->b, array[i])
	the total rotational cost is 
	min(max(a_i, b_i), max(size_a - a_i, size_b - b_i))
	choose the smallest cost, and make the moves.
*/
void	choose_and_make_moves(t_data *data, long *array)
{
	int	i;
	int	min;
	int	returns[2];
	int	temp;

	i = 0;
	min = INT_MAX;
	returns[0] = 0;
	returns[1] = 0;
	while (i < 2 * data->size_a)
	{
		if (array[i] >= INT_MIN && array[i] <= INT_MAX)
		{
			temp = calculate_cost(data, i / 2, index_of(data->b, array[i]));
			if (temp + (i % 2) < min)
			{
				min = temp + (i % 2);
				returns[0] = (i / 2) + (i % 2);
				returns[1] = array[i];
			}
		}
		++i;
	}
	move_to_a(data, returns[0], returns[1]);
}
