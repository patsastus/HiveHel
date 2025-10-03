/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:04:59 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/03 12:27:53 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

t_philo	*init_philosopher(unsigned int id, unsigned long start, \
t_table *table)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->start = start;
	philo->last_meal = start;
	philo->time_to_die = table->time_to_die;
	philo->time_to_eat = table->time_to_eat;
	philo->time_to_sleep = table->time_to_sleep;
	philo->meals_goal = table->required_meals;
	return (philo);
}

void	init_philos(t_table *table, unsigned long start)
{
	unsigned int	i;

	table->start = start;
	table->philos = malloc(sizeof(void *) * table->count);
	if (!table->philos)
	{
		table->error_flag = 1;
		return ;
	}
	memset(table->philos, 0, sizeof(void *) * table->count);
	i = 0;
	while (i < table->count)
	{
		table->philos[i] = init_philosopher(i + 1, start, table);
		if (table->philos[i] == NULL)
		{
			table->error_flag = 2;
			return ;
		}
		++i;
	}
}

/*
	Due to lack of signal handling allowed, it's impossible to ensure sempahores
 	weren't previously initialized, so need to be unlinked pre-emptively
*/
void	init_semaphores(t_table *table)
{
	sem_unlink(FORKS_SEM_NAME);
	sem_unlink(DEATH_SEM_NAME);
	sem_unlink(WRITE_SEM_NAME);
	sem_unlink(FORK_MUTEX);
	table->forks = sem_open(FORKS_SEM_NAME, O_CREAT, 0600, table->count);
	table->death = sem_open(DEATH_SEM_NAME, O_CREAT, 0600, 0);
	table->write = sem_open(WRITE_SEM_NAME, O_CREAT, 0600, 1);
	table->fork_mutex = sem_open(FORK_MUTEX, O_CREAT, 0600, 1);
	if (table->forks == SEM_FAILED || table->write == SEM_FAILED || \
table->death == SEM_FAILED || table->fork_mutex == SEM_FAILED)
	{
		printf("sem_open failed\n");
		table->error_flag = 3;
	}
}


