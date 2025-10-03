/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:41 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/30 14:36:20 by nraatika         ###   ########.fr       */
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
	philo->count = table->count;
	philo->start = start;
	philo->last_meal = start;
	philo->write_mutex = &(table->write_mutex);
	pthread_mutex_init(&(philo->own_fork), NULL);
	pthread_mutex_init(&(philo->monitor_mutex), NULL);
	philo->time_to_die = table->time_to_die;
	philo->time_to_eat = table->time_to_eat;
	philo->time_to_sleep = table->time_to_sleep;
	philo->meals_goal = table->required_meals;
	philo->should_stop = &(table->someone_died);
	return (philo);
}

void	take_forks(t_philo *philo)
{
	unsigned long	time;
	pthread_mutex_t	*temp;

	if (philo->id == 1)
		temp = &(philo->own_fork);
	else
		temp = philo->other_fork;
	if (!temp)
		return ;
	pthread_mutex_lock(temp);
	time = gettime_in_ms();
	if (time - philo->last_meal <= philo->time_to_die)
		write_message('f', philo, time);
	if (philo->id == 1)
		temp = philo->other_fork;
	else
		temp = &(philo->own_fork);
	pthread_mutex_lock(temp);
	time = gettime_in_ms();
	if (time - philo->last_meal <= philo->time_to_die)
		write_message('f', philo, time);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->own_fork));
	if (philo->other_fork)
		pthread_mutex_unlock(philo->other_fork);
}

void	*loop_philo(void *input)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = input;
	if (philo->id % 2 == 0)
		targeted_sleep(philo, philo->start + philo->time_to_eat + 10);
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
	return (NULL);
}
