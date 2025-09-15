/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:28:31 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/12 14:57:43 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	const char	*msg = "%u %d is eating meal %d\n";

	take_forks(philo);
	pthread_mutex_lock(&(philo->monitor_mutex));
	if (gettime_in_ms() - philo->last_meal_time > philo->time_to_die)
	{
		philo->dead = 1;
		release_forks(philo, 1);
		pthread_mutex_unlock(&(philo->monitor_mutex));
		return ;
	}
	else
	{
		philo->last_meal_time = gettime_in_ms();
		philo->current_action = 'e';
		philo->meals_eaten += 1;
	}
	pthread_mutex_unlock(&(philo->monitor_mutex));
	pthread_mutex_lock(philo->write_mutex);
	printf(msg, (gettime_in_ms() - philo->start), philo->id, \
philo->meals_eaten);
	pthread_mutex_unlock(philo->write_mutex);
	more_exact_sleep(philo->last_meal_time + philo->time_to_eat);
	release_forks(philo, 0);
}

void	sleeping(t_philo *philo)
{
	const char		*msg = "%u %d is sleeping\n";
	unsigned long	time;

	time = gettime_in_ms();
	pthread_mutex_lock(&(philo->monitor_mutex));
	philo->current_action = 's';
	pthread_mutex_unlock(&(philo->monitor_mutex));
	pthread_mutex_lock(philo->write_mutex);
	printf(msg, (gettime_in_ms() - philo->start), philo->id);
	pthread_mutex_unlock(philo->write_mutex);
	more_exact_sleep(time + philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	const char	*msg = "%u %d is thinking\n";

	pthread_mutex_lock(&(philo->monitor_mutex));
	if (philo->meals_eaten == 0)
		philo->last_meal_time = gettime_in_ms();
	if (philo->current_action == 't')
	{
		pthread_mutex_unlock(&(philo->monitor_mutex));
		return ;
	}
	philo->current_action = 't';
	pthread_mutex_unlock(&(philo->monitor_mutex));
	pthread_mutex_lock(philo->write_mutex);
	printf(msg, (gettime_in_ms() - philo->start), philo->id);
	pthread_mutex_unlock(philo->write_mutex);
}

void	dying(t_philo *philo)
{
	const char	*msg = "%u %d died\n";

	pthread_mutex_lock(&(philo->monitor_mutex));
	philo->dead = 1;
	pthread_mutex_unlock(&(philo->monitor_mutex));
	pthread_mutex_lock(philo->write_mutex);
	printf(msg, (gettime_in_ms() - philo->start), philo->id);
	pthread_mutex_unlock(philo->write_mutex);
}
