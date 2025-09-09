/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:34:30 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/09 12:51:20 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	run_table(t_table *table)
{
	const char	*msg = "running table\n";

	(void)table;
	write(1, msg, ft_strlen(msg));
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = parse_to_table(argc, argv);
	if (!table)
		return (1);
	run_table(table);
	free(table);
	return (0);
}
