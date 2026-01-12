/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:28:31 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/16 10:51:14 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	unsigned long	time;

	if (philo->dead)
		return ;
	take_forks(philo);
	pthread_mutex_lock(&(philo->monitor_mutex));
	time = gettime_in_ms();
	if (philo->dead || time - philo->last_meal > philo->time_to_die)
	{
		release_forks(philo);
		pthread_mutex_unlock(&(philo->monitor_mutex));
		dying(philo, 0);
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
	release_forks(philo);
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
	write_message('s', philo, time);
	targeted_sleep(philo, philo->time_to_sleep + time);
}

void	thinking(t_philo *philo)
{
	unsigned long	time;
	long			target;

	if (philo->dead || philo->current_action == 't')
		return ;
	pthread_mutex_lock(&(philo->monitor_mutex));
	philo->current_action = 't';
	time = gettime_in_ms();
	write_message('t', philo, time);
	pthread_mutex_unlock(&(philo->monitor_mutex));
	target = philo->time_to_die - (time - philo->last_meal) \
- philo->time_to_eat / 2;
	if (target > 0 && philo->meals_eaten != 0)
	{
		if (target <= philo->time_to_eat)
			targeted_sleep(philo, time + target);
		else if (target > philo->time_to_eat)
			targeted_sleep(philo, time + philo->time_to_eat + 5);
	}
	else if (philo->meals_eaten == 0 && !(philo->id % 2))
		targeted_sleep(philo, philo->start + philo->time_to_eat + 10);
}

void	dying(t_philo *philo, int silent)
{
	unsigned long	time;

	if (philo->dead)
		return ;
	pthread_mutex_lock(&(philo->monitor_mutex));
	philo->dead = 1 + silent;
	if (philo->dead == 1)
	{
		time = gettime_in_ms();
		write_message('d', philo, time);
	}
	pthread_mutex_unlock(&(philo->monitor_mutex));
}
