/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:28:31 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/18 12:01:15 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	unsigned long	time;

	take_forks(philo);
	time = gettime_in_ms();
	if (time == ULONG_MAX)
		dying(philo, 5);
	pthread_mutex_lock(&(philo->monitor_mutex));
	if (time - philo->last_meal > philo->time_to_die)
	{
		pthread_mutex_unlock(&(philo->monitor_mutex));
		release_forks(philo, 0);
		dying(philo, (int)philo->dead);
		return ;
	}
	else
	{
		philo->last_meal = time;
		philo->current_action = 'e';
		philo->meals_eaten += 1;
	}
	pthread_mutex_unlock(&(philo->monitor_mutex));
	write_message('e', philo, time);
	targeted_sleep(philo, philo->time_to_eat + time);
	release_forks(philo, 0);
}

void	sleeping(t_philo *philo)
{
	unsigned long	time;

	if (philo->dead)
		return ;
	pthread_mutex_lock(&(philo->monitor_mutex));
	philo->current_action = 's';
	pthread_mutex_unlock(&(philo->monitor_mutex));
	time = gettime_in_ms();
	if (time == ULONG_MAX)
		dying(philo, 5);
	write_message('s', philo, time);
	targeted_sleep(philo, philo->time_to_sleep + time);
}

void	thinking(t_philo *philo)
{
	unsigned long	time;

	pthread_mutex_lock(&(philo->monitor_mutex));
	if (philo->current_action == 't')
	{
		pthread_mutex_unlock(&(philo->monitor_mutex));
		return ;
	}
	philo->current_action = 't';
	pthread_mutex_unlock(&(philo->monitor_mutex));
	time = gettime_in_ms();
	if (time == ULONG_MAX)
		dying(philo, 5);
	write_message('t', philo, time);
}

void	dying(t_philo *philo, int silent)
{
	unsigned long	time;

	pthread_mutex_lock(&(philo->monitor_mutex));
	philo->dead = 1 + silent;
	pthread_mutex_unlock(&(philo->monitor_mutex));
	if (!silent)
	{
		time = gettime_in_ms();
		write_message('d', philo, time);
	}
}
