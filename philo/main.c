/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:34:30 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/12 11:29:34 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philos(t_table *table, long start_time)
{
	unsigned int	i;

	table->start_time = start_time;
	table->philos = malloc(sizeof(void *) * table->count);
	if (!table->philos)
	{
		table->error_flag = 1;
		return ;
	}
	i = 0;
	while (i < table->count)
	{
		table->philos[i] = init_philosopher(i + 1, start_time, table);
		++i;
	}
	i = 1;
	while (i < table->count)
	{
		table->philos[i]->other_fork = &(table->philos[i - 1]->own_fork);
		++i;
	}
	if (table->count > 1)
		table->philos[0]->other_fork = &(table->philos[i - 1]->own_fork);
}

static void	run_table(t_table *table, long start_time)
{
	unsigned int	i;

	init_philos(table, start_time);
	i = 0;
	pthread_create(&(table->monitor), NULL, monitor, (void *)table);
	while (i < table->count)
	{
		pthread_create(&(table->philos[i]->thread), NULL, loop_philo, \
(void *)table->philos[i]);
		++i;
	}
	pthread_join(table->monitor, NULL);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = parse_to_table(argc, argv);
	if (!table || table->count == 0)
		return (1);
	run_table(table, gettime_in_ms());
	free_table(table);
	return (0);
}
