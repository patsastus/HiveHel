/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:34:30 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/18 12:03:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define _GNU_SOURCE	
#include "philosophers.h"

static void	init_philos(t_table *table, unsigned long start)
{
	unsigned int	i;

	table->start = start;
	table->philos = malloc(sizeof(void *) * table->count);
	if (!table->philos)
	{
		table->error_flag = 1;
		return ;
	}
	i = 0;
	while (i < table->count)
	{
		table->philos[i] = init_philosopher(i + 1, start, table);
		if (table->philos[i] == NULL)
			return ;
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

static void	run_table(t_table *table, unsigned long start)
{
	const char		*msg = "%u philosophers arrive at a table\n";
	char			*temp;
	unsigned int	i;

	printf(msg, table->count);
	init_philos(table, start);
	i = 0;
	temp = malloc(10);
	memset(temp, 0, 10);
	if (pthread_create(&(table->monitor), NULL, monitor, (void *)table))
	{
		free_table(table, 0, 0);
		return ;
	}
	pthread_setname_np(table->monitor, "monitor");
	while (i < table->count)
	{
		if (pthread_create(&(table->philos[i]->thread), NULL, loop_philo, \
(void *)table->philos[i]))
		{
			free_table(table, 1, i);
			return ;
		}
		sprintf(temp, "philo%u", table->philos[i]->id);
		pthread_setname_np(table->philos[i]->thread, temp);
		++i;
	}
	free(temp);
	pthread_join(table->monitor, NULL);
	free_table(table, 0, table->count);
}

void	end_all_philo_threads(t_table *table, unsigned int num_philos)
{
	unsigned int	i;

	i = 0;
	while (i < table->count)
	{
		pthread_mutex_lock(&(table->philos[i]->monitor_mutex));
		if (!(table->philos[i]->dead))
			table->philos[i]->dead = 2;
		pthread_mutex_unlock(&(table->philos[i]->monitor_mutex));
		++i;
	}
	usleep(BLINK * 2);
	i = 0;
	while (i < num_philos)
	{
		pthread_join(table->philos[i]->thread, NULL);
		++i;
	}
}

void	free_table(t_table *table, int monitor, int num_philos)
{
	unsigned int	i;

	i = 0;
	end_all_philo_threads(table, num_philos);
	while (i < table->count)
	{
		pthread_mutex_destroy(&(table->philos[i]->monitor_mutex));
		pthread_mutex_destroy(&(table->philos[i]->own_fork));
		free(table->philos[i]);
		++i;
	}
	free(table->philos);
	if (monitor)
		pthread_join(table->monitor, NULL);
	pthread_mutex_destroy(&(table->write_mutex));
	free(table);
}

int	main(int argc, char **argv)
{
	t_table			*table;
	unsigned long	time;

	table = parse_to_table(argc, argv);
	if (!table || table->count == 0)
		return (1);
	time = gettime_in_ms();
	if (time == ULONG_MAX)
		return (1);
	run_table(table, time);
	return (0);
}
