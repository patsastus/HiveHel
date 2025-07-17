/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:03:58 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:22:46 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
 *loop through provided arguments, validate that the contain only unique 
 *integers, and add them to the provided data structure
 */
void	parse_validate_input(t_data *data, int argc, char **argv)
{
	int		index;
	int		tmp;
	t_list	*candidates;

	index = 1;
	while (index < argc)
	{
		candidates = parse_input_argument(argv[index]);
		if (!candidates)
			free_and_exit(candidates);
		tmp = check_duplicate_in(data, candidates);
		if (!tmp)
			ft_lstadd_back(&(data->a), candidates);
		else
			free_and_exit(candidates);
		++index;
	}
	data->stack_size = ft_lstsize(data->a);
	data->size_a = data->stack_size;
}

/*
	Parses the string passed as arguments.
	Returns a linked list of the integer(s) found in the string.
	Exits and frees memory on any illegal input (non-digit/sign/spaces, 
	over-/under-flow), or if any node creation fails
*/
t_list	*parse_input_argument(char *str)
{
	t_list	*tmp;
	t_list	*head;
	int		val;
	int		read;

	head = NULL;
	while (*str)
	{
		while (*str == ' ')
			++str;
		if (!(*str))
			break ;
		read = atoi_check(&val, str);
		str += read;
		if (head && !(*str == ' ' || *str == '\0'))
			free_and_exit(head);
		tmp = make_list_node(val);
		if (!tmp)
			free_and_exit(head);
		ft_lstadd_back(&head, tmp);
		if (read == -1)
			free_and_exit(head);
	}
	return (head);
}

/*
	Tries to form an integer from the argument str, and store it in the argument
	ptr.
	Returns the number of characters read from str, or -1 in case of illegal
	input or over/under-flow
*/
int	atoi_check(int *ptr, char *str)
{
	long	value;
	int		read;
	int		sign;

	sign = 1;
	read = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++read;
	}
	if (!ft_isdigit(str[read]))
		return (-1);
	value = 0;
	while (ft_isdigit(str[read]))
	{
		value *= 10;
		value += str[read] - '0';
		if ((sign == 1 && value > INT_MAX) || (sign == -1 && - value < INT_MIN))
			return (-1);
		++read;
	}
	*ptr = (int)(value * sign);
	return (read);
}

void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->stack_size = 0;
	data->size_a = 0;
	data->size_b = 0;
	data->funcs[0] = swap_a;
	data->funcs[1] = swap_b;
	data->funcs[2] = swap_both;
	data->funcs[3] = push_a;
	data->funcs[4] = push_b;
	data->funcs[5] = rotate_a;
	data->funcs[6] = rotate_b;
	data->funcs[7] = rotate_both;
	data->funcs[8] = rev_rotate_a;
	data->funcs[9] = rev_rotate_b;
	data->funcs[10] = rev_rotate_both;
}
