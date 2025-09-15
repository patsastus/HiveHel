/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:13:40 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/12 14:02:24 by nraatika         ###   ########.fr       */
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

void	*monitor(void *input)
{
	t_table			*table;
	unsigned int	i;

	table = input;
	while (1)
	{
		i = 0;
		while (i < table->count)
		{
			pthread_mutex_lock(&(table->philos[i]->monitor_mutex));
			if (gettime_in_ms() - table->philos[i]->last_meal_time > table->\
time_to_die)
			{
				pthread_mutex_unlock(&(table->philos[i]->monitor_mutex));
				dying(table->philos[i]);
				table->someone_died = (char)(i + 1);
				return (NULL);
			}
			pthread_mutex_unlock(&(table->philos[i]->monitor_mutex));
			++i;
		}
		if (all_eaten(table))
			return (NULL);
		usleep(MS);
	}
}
