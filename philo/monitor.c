/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:13:40 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/18 10:54:07 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	all_eaten(t_table *table)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	while (i < table->count)
	{
		pthread_mutex_lock(&(table->philos[i]->monitor_mutex));
		if (table->philos[i]->meals_eaten == table->philos[i]->meals_goal && \
table->philos[i]->current_action != 'e')
			++count;
		pthread_mutex_unlock(&(table->philos[i]->monitor_mutex));
		++i;
	}
	if (count == table->count)
		return (1);
	else
		return (0);
}

static int	should_philo_die(t_table *table, int i, unsigned long time)
{
	pthread_mutex_lock(&(table->philos[i]->monitor_mutex));
	if (time - table->philos[i]->last_meal > table->time_to_die)
	{
		pthread_mutex_unlock(&(table->philos[i]->monitor_mutex));
		dying(table->philos[i], 0);
		table->someone_died = (char)(i + 1);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(table->philos[i]->monitor_mutex));
		return (0);
	}
}

void	*monitor(void *input)
{
	t_table			*table;
	unsigned int	i;
	unsigned long	time;
	unsigned int	loop;

	loop = 0;
	table = input;
	while (!table->someone_died)
	{
		i = 0;
		time = gettime_in_ms();
		while (i < table->count && time != ULONG_MAX)
		{
			should_philo_die(table, i, time);
			++i;
		}
		if (all_eaten(table))
			return (NULL);
		usleep(MS);
	}
	return (NULL);
}
