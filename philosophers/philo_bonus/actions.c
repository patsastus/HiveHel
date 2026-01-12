/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:28:31 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/15 12:10:21 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	unsigned long	time;

	if (philo->dead)
		return ;
	take_forks(philo);
	sem_wait(philo->self_mutex);
	time = gettime_in_ms();
	if (time - philo->last_meal > philo->time_to_die)
	{
		release_forks(philo);
		dying(philo, (int)philo->dead);
		return ;
	}
	else
	{
		philo->last_meal = time;
		philo->current_action = 'e';
		philo->meals_eaten += 1;
	}
	write_message('e', philo, time);
	sem_post(philo->self_mutex);
	targeted_sleep(philo, philo->time_to_eat + time);
	release_forks(philo);
}

void	sleeping(t_philo *philo)
{
	unsigned long	time;

	if (philo->dead)
		return ;
	philo->current_action = 's';
	time = gettime_in_ms();
	write_message('s', philo, time);
	targeted_sleep(philo, philo->time_to_sleep + time);
}

void	thinking(t_philo *philo)
{
	unsigned long	time;

	if (philo->dead)
		return ;
	time = gettime_in_ms();
	if (time - philo->last_meal > philo->time_to_die)
	{
		dying(philo, 0);
		return ;
	}
	if (philo->current_action == 't')
		return ;
	philo->current_action = 't';
	write_message('t', philo, time);
}

void	dying(t_philo *philo, int silent)
{
	unsigned long	time;

	if (!silent)
	{
		time = gettime_in_ms();
		write_message('d', philo, time);
		sem_post(philo->death);
	}
	philo->dead = 1 + silent;
}

void	release_forks(t_philo *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
}
