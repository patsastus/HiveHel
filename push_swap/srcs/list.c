/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:40:41 by nraatika          #+#    #+#             */
/*   Updated: 2025/06/24 14:56:45 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
	First check whether current candidate is duplicated in candidate list, then
	check against what's already in data
*/
int	check_duplicate_in(t_data *data, t_list *candidates)
{
	t_list	*temp;
	t_list	*copy;

	while (candidates != NULL)
	{
		temp = data->a;
		copy = candidates->next;
		while (copy != NULL)
		{
			if (*(int *)(candidates->content) == *(int *)(copy->content))
				return (1);
			copy = copy->next;
		}
		while (temp != NULL)
		{
			if (*(int *)(candidates->content) == *(int *)(temp->content))
				return (1);
			temp = temp->next;
		}
		candidates = candidates->next;
	}
	return (0);
}

void	rotate_list(t_list **list)
{
	t_list	*temp;

	if (!*list)
		return ;
	temp = *list;
	*list = (*list)->next;
	temp->next = NULL;
	ft_lstadd_back(list, temp);
}

void	rev_rotate_list(t_list **list)
{
	t_list	*last;
	t_list	*next_to_last;

	if (!*list || ft_lstsize(*list) < 2)
		return ;
	next_to_last = *list;
	while (next_to_last->next->next != NULL)
		next_to_last = next_to_last->next;
	last = next_to_last->next;
	next_to_last->next = NULL;
	ft_lstadd_front(list, last);
}

void	swap_top_two(t_list **stack)
{
	t_list	*temp[2];

	temp[0] = *stack;
	temp[1] = temp[0]->next;
	*stack = temp[1];
	temp[0]->next = temp[1]->next;
	temp[1]->next = temp[0];
}

t_list	*make_list_node(int content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = malloc(sizeof(int));
	if (!(tmp->content))
	{
		free(tmp);
		return (NULL);
	}
	*(int *)(tmp->content) = content;
	tmp->next = NULL;
	return (tmp);
}
