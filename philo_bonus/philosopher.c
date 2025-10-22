/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:41 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/15 15:32:42 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*should_stop_watcher(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	sem_wait(philo->death);
	sem_post(philo->death);
	philo->should_stop = 1;
	usleep(MS);
	return (NULL);
}

void	*should_die(void *input)
{
	t_table			*table;
	t_philo			*philo;
	unsigned long	time;

	table = (t_table *)input;
	philo = table->philos[table->loop_index];
	sem_wait(philo->self_mutex);
	while (!philo->should_stop && !philo->dead)
	{
		time = gettime_in_ms();
		if (time - philo->last_meal > philo->time_to_die)
		{
			dying(philo, 0);
			usleep(MS);
			free_philo(table);
			exit(1);
		}
		sem_post(philo->self_mutex);
		usleep(MS);
		sem_wait(philo->self_mutex);
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

static int	action_loop(t_philo *philo)
{
	thinking(philo);
	eating(philo);
	if (philo->meals_eaten == philo->meals_goal)
	{
		philo->should_stop = 1;
		return (1);
	}
	sleeping(philo);
	usleep(BLINK);
	return (0);
}

void	loop_philo(void *input)
{
	t_philo		*philo;
	pthread_t	someone_died_thread;
	pthread_t	self_died_thread;
	int			v;

	philo = ((t_table *)input)->philos[((t_table *)input)->loop_index];
	v = pthread_create(&someone_died_thread, NULL, should_stop_watcher, philo);
	if (!v)
		v = pthread_create(&self_died_thread, NULL, should_die, input) * 2;
	if (v != -1)
		pthread_detach(someone_died_thread);
	while (!v && !philo->dead && !philo->should_stop && !action_loop(philo))
		continue ;
	if (v == 0)
		pthread_join(self_died_thread, NULL);
	v = !(philo->meals_eaten == philo->meals_goal);
	free_philo((t_table *)input);
	exit(v);
}
