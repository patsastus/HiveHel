/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:26:37 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/12 14:59:27 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	more_exact_sleep(t_philo *philo, long target)
{
	
}

void	end_all_philo_threads(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->count)
	{
		pthread_mutex_lock(&(table->philos[i]->monitor_mutex));
		if (!(table->philos[i]->dead))
			table->philos[i]->dead = 2;
		if (table->philos[i]->current_action == 'e')
			release_forks(table->philos[i], 1);
		pthread_mutex_unlock(&(table->philos[i]->monitor_mutex));
		++i;
	}
	i = 0;
	while (i < table->count)
	{
		pthread_join(table->philos[i]->thread, NULL);
		++i;
	}
}

void	free_table(t_table *table)
{
	unsigned int	i;

	end_all_philo_threads(table);
	i = 0;
	while (i < table->count)
	{
		pthread_mutex_destroy(&(table->philos[i]->monitor_mutex));
		pthread_mutex_destroy(&(table->philos[i]->own_fork));
		free(table->philos[i]);
		++i;
	}
	free(table->philos);
	pthread_mutex_destroy(&(table->write_mutex));
	free(table);
}

//returns a timestamp in milliseconds
unsigned long	gettime_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((unsigned long)((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	if (s == NULL)
		return (0);
	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}
