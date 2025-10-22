/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:04:59 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/15 11:48:13 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	make_threads(pthread_t *threads, t_table *table)
{
	int		value[2];
	t_philo	*philo;

	philo = table->philos[table->loop_index];
	value[0] = pthread_create(&threads[0], NULL, should_stop_watcher, philo);
	if (!value[0])
	{
		pthread_detach(threads[0]);
		value[1] = pthread_create(&threads[1], NULL, should_die, table);
	}
	return (value[0] * 2 + value[1]);
}

/*
	init a personalized semaphore name for each philo, unlink it in case it
	already existed, and open it
*/
void	init_philo_semaphores(t_philo *philo)
{
	const char	*template = "/philo000";
	int			i;
	int			temp;

	philo->forks = sem_open(FORKS_SEM_NAME, 0);
	philo->write = sem_open(WRITE_SEM_NAME, 0);
	philo->death = sem_open(DEATH_SEM_NAME, 0);
	philo->fork_mutex = sem_open(FORK_MUTEX, 0);
	i = -1;
	while (++i < 9)
		philo->self_mutex_name[i] = template[i];
	temp = philo->id / 10;
	i = 7;
	philo->self_mutex_name[8] = philo->id % 10 + '0';
	while (temp > 0)
	{
		philo->self_mutex_name[i] = temp % 10 + '0';
		temp /= 10;
		--i;
	}
	sem_unlink(philo->self_mutex_name);
	philo->self_mutex = sem_open(philo->self_mutex_name, O_CREAT, 0600, 1);
}

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
