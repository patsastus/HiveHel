/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:58:41 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/09 12:49:08 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philosopher(int id, int current_time, t_philo *philo)
{
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->last_meal_time = current_time;
	pthread_mutex_init(&(philo->fork), NULL);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->fork));
}

void	loop_philosopher(t_philo *philo)
{
	(void)philo;
}
