/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:34:30 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/01 13:58:29 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

static void	init_philos(t_table *table, unsigned long start)
{
	unsigned int	i;

	table->philos = malloc(sizeof(void *) * table->count);
	if (!table->philos)
	{
		table->error_flag = 1;
		return ;
	}
	i = -1;
	while (++i < table->count)
	{
		table->philos[i] = init_philosopher(i + 1, start, table);
		if (table->philos[i] == NULL)
		{
			table->error_flag = 2 + i;
			return ;
		}
	}
	i = 0;
	while (++i < table->count)
		table->philos[i]->other_fork = &(table->philos[i - 1]->own_fork);
	if (table->count > 1)
		table->philos[0]->other_fork = &(table->philos[i - 1]->own_fork);
}

static void	run_table(t_table *table, unsigned long start)
{
	unsigned int	i;

	init_philos(table, start);
	if (table->error_flag)
	{
		free_table(table, 0, 0);
		return ;
	}
	i = -1;
	pthread_create(&(table->monitor), NULL, monitor, (void *)table);
	while (++i < table->count)
	{
		if (pthread_create(&(table->philos[i]->thread), NULL, loop_philo, \
(void *)table->philos[i]))
		{
			free_table(table, 1, i);
			return ;
		}
	}
	pthread_join(table->monitor, NULL);
}

void	end_all_philo_threads(t_table *table, unsigned int num_philos)
{
	unsigned int	i;

	i = 0;
	while (i < table->count && table->philos != NULL)
	{
		pthread_mutex_lock(&(table->philos[i]->monitor_mutex));
		if (!(table->philos[i]->dead))
			table->philos[i]->dead = 2;
		pthread_mutex_unlock(&(table->philos[i]->monitor_mutex));
		++i;
	}
	usleep(MS);
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
	while (i < table->count && table->philos != NULL)
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
	if (!table)
		return (1);
	time = gettime_in_ms();
	if (time == ULONG_MAX || table->count == 0)
	{
		free_table(table, 0, 0);
		return (1);
	}
	table->start = time;
	run_table(table, time);
	free_table(table, 0, table->count);
	return (0);
}
