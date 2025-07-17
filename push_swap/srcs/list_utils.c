/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:05:01 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/01 10:59:03 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	list_max(t_list *list)
{
	int	temp;

	temp = INT_MIN;
	while (list != NULL)
	{
		if (*(int *)(list->content) > temp)
			temp = *(int *)(list->content);
		list = list->next;
	}
	return (temp);
}

int	list_min(t_list *list)
{
	int	temp;

	temp = INT_MAX;
	while (list != NULL)
	{
		if (*(int *)(list->content) < temp)
			temp = *(int *)(list->content);
		list = list->next;
	}
	return (temp);
}

ssize_t	index_of(t_list *list, int value)
{
	ssize_t	temp;

	temp = 0;
	while (list != NULL)
	{
		if (*(int *)(list->content) == value)
			return (temp);
		++temp;
		list = list->next;
	}
	return (-1);
}

int	get_mean(t_list *stack)
{
	size_t	count;
	long	sum;

	sum = 0;
	count = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		sum += *(int *)stack->content;
		++count;
		stack = stack->next;
	}
	return ((int)(sum / count));
}

int	get_median(t_list *stack, int index, int num_medians)
{
	int		count;
	int		target;
	t_list	*copies[2];

	copies[0] = stack;
	target = ft_lstsize(stack) * (index + 1) / (num_medians + 1);
	while (stack != NULL)
	{
		count = 0;
		copies[1] = copies[0];
		while (copies[1] != NULL)
		{
			if (*(int *)copies[1]->content <= *(int *)stack->content)
				count++;
			copies[1] = copies[1]->next;
		}
		if (count == target)
			return (*(int *)stack->content);
		stack = stack->next;
	}
	return (INT_MIN);
}
