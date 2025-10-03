/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:41 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/03 14:12:45 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*should_stop_watcher(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	sem_wait(philo->death);
	sem_post(philo->death);
	philo->should_stop = 1;
	usleep(BLINK);
	return (NULL);
}

static void	*should_die(void *input)
{
	t_philo			*philo;
	unsigned long	time;

	philo = (t_philo *)input;
	while (!philo->should_stop && !philo->dead)
	{
		time = gettime_in_ms();
		if (time - philo->last_meal > philo->time_to_die)
		{
			dying(philo, 0);
			usleep(MS);
			free_philo(philo);
		}
		usleep(MS);
	}
	return (NULL);
}

void	take_forks(t_philo *philo)
{
	unsigned long	time;

	sem_wait(philo->fork_mutex);
	sem_wait(philo->forks);
	time = gettime_in_ms();
	write_message('f', philo, time);
	sem_wait(philo->forks);
	time = gettime_in_ms();
	write_message('f', philo, time);
	sem_post(philo->fork_mutex);
}

void	release_forks(t_philo *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	loop_philo(void *input)
{
	t_philo		*philo;
	pthread_t	someone_died_thread;
	pthread_t	self_died_thread;
	int			value;

	philo = (t_philo *)input;
	pthread_create(&someone_died_thread, NULL, should_stop_watcher, philo);
	pthread_create(&self_died_thread, NULL, should_die, philo);
	pthread_detach(someone_died_thread);
	while (!philo->dead && !philo->should_stop)
	{
		thinking(philo);
		eating(philo);
		if (philo->meals_eaten == philo->meals_goal)
		{
			philo->should_stop = 1;
			break ;
		}
		sleeping(philo);
		usleep(BLINK);
	}
	pthread_join(self_died_thread, NULL);
	value = !(philo->meals_eaten == philo->meals_goal);
	free_philo(philo);
	exit(value);
}
