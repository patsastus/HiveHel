/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:41 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/12 14:43:13 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*init_philosopher(unsigned int id, unsigned long start_time, \
t_table *table)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->start = start_time;
	philo->last_meal_time = start_time;
	philo->write_mutex = &(table->write_mutex);
	pthread_mutex_init(&(philo->own_fork), NULL);
	pthread_mutex_init(&(philo->monitor_mutex), NULL);
	philo->time_to_die = table->time_to_die;
	philo->time_to_eat = table->time_to_eat;
	philo->time_to_sleep = table->time_to_sleep;
	philo->meals_goal = table->required_meals;
	return (philo);
}

void	take_forks(t_philo *philo)
{
	const char		*msg = "%u %d has taken fork %d\n";
	pthread_mutex_t	*temp;

	if (philo->id % 2)
		temp = &(philo->own_fork);
	else
		temp = philo->other_fork;
	if (!temp)
		return ;
	pthread_mutex_lock(temp);
	if (philo->id % 2)
		temp = philo->other_fork;
 	else
		temp = &(philo->own_fork);
	pthread_mutex_lock(temp);
	pthread_mutex_lock(philo->write_mutex);
	if (philo->id % 2)
		printf(msg, (gettime_in_ms() - philo->start), philo->id, philo->id - 1);
	printf(msg, (gettime_in_ms() - philo->start), philo->id, philo->id);
	if (!(philo->id % 2))
		printf(msg, (gettime_in_ms() - philo->start), philo->id, philo->id - 1);
	pthread_mutex_unlock(philo->write_mutex);
}

void	release_forks(t_philo *philo, int silent)
{
	const char	*msg = "%u %d has released forks\n";

	pthread_mutex_unlock(&(philo->own_fork));
	pthread_mutex_unlock(philo->other_fork);
	if (!silent)
	{
		pthread_mutex_lock(philo->write_mutex);
		printf(msg, (gettime_in_ms() - philo->start), philo->id);
		pthread_mutex_unlock(philo->write_mutex);
	}
}

void	*loop_philo(void *input)
{
	t_philo	*philo;

	philo = input;
	if (philo->id % 2)
		usleep(BLINK);
	pthread_mutex_lock(&(philo->monitor_mutex));
	while (!philo->dead && philo->meals_eaten < philo->meals_goal)
	{
		pthread_mutex_unlock(&(philo->monitor_mutex));
		usleep(BLINK);
		thinking(philo);
		if (philo->other_fork)
		{
			eating(philo);
			if (!philo->dead)
				sleeping(philo);
		}
		pthread_mutex_lock(&(philo->monitor_mutex));
	}
		pthread_mutex_unlock(&(philo->monitor_mutex));
	return (NULL);
}
