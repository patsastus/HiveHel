/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:02:52 by nraatika          #+#    #+#             */
/*   Updated: 2025/06/30 14:32:51 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

/*
	exit after freeing all allocated memory in the data structure.
*/
static void	ft_exit(int error)
{
	t_data	*data;

	data = get_data();
	ft_lstclear(&(data->a), free);
	ft_lstclear(&(data->b), free);
	if (error)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else
		exit(0);
}

void	free_and_exit(t_list *ptr)
{
	if (ptr)
		ft_lstclear(&ptr, free);
	ft_exit(1);
}

/*
	initializes data, parses and validates input, then checks whether the data 
	is already sorted. If not, sorts the data.
*/
int	main(int argc, char **argv)
{
	t_data		*data;

	data = get_data();
	init_data(data);
	if (argc == 1)
		return (0);
	parse_validate_input(data, argc, argv);
	if (!is_sorted(data))
		sort_bucket(data);
	ft_exit(0);
	return (0);
}
