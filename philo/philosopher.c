/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:41 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/18 12:04:42 by nraatika         ###   ########.fr       */
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
	unsigned long	time;
	pthread_mutex_t	*temp;

	if (philo->dead)
		return ;
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
	pthread_mutex_lock(&(philo->monitor_mutex));
	philo->holding = 1;
	pthread_mutex_unlock(&(philo->monitor_mutex));
	pthread_mutex_lock(philo->write_mutex);
	printf("%u holding\n", philo->id);
	pthread_mutex_unlock(philo->write_mutex);
	time = gettime_in_ms();
	if (time == ULONG_MAX)
		return ;
	write_message('f', philo, time);
}

void	release_forks(t_philo *philo, int silent)
{
	unsigned long	time;

	if (philo->dead)
		silent = 1;
	time = gettime_in_ms();
	pthread_mutex_unlock(&(philo->own_fork));
	pthread_mutex_unlock(philo->other_fork);
	pthread_mutex_lock(&(philo->monitor_mutex));
	philo->holding = 0;
	pthread_mutex_unlock(&(philo->monitor_mutex));
	pthread_mutex_lock(philo->write_mutex);
	printf("%u releasing\n", philo->id);
	pthread_mutex_unlock(philo->write_mutex);
	if (!silent)
		write_message('r', philo, time);
}

void	*loop_philo(void *input)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = input;
	if (philo->id % 2)
		usleep(BLINK);
	while (!philo->dead && philo->meals_eaten < philo->meals_goal)
	{
		thinking(philo);
		if (philo->other_fork)
		{
			eating(philo);
			sleeping(philo);
		}
		usleep(BLINK);
	}
	pthread_mutex_lock(&(philo->monitor_mutex));
	if (philo->holding)
	{
		pthread_mutex_unlock(&(philo->monitor_mutex));
		release_forks(philo, 0);
	}
	else
		pthread_mutex_unlock(&(philo->monitor_mutex));
	return (NULL);
}
