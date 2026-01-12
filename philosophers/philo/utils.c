/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:26:37 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/13 12:37:27 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	targeted_sleep(t_philo *philo, unsigned long target)
{
	unsigned long	temp;

	temp = gettime_in_ms();
	pthread_mutex_lock(&(philo->monitor_mutex));
	while (temp < target && !philo->dead)
	{
		pthread_mutex_unlock(&(philo->monitor_mutex));
		usleep(BLINK);
		temp = gettime_in_ms();
		pthread_mutex_lock(&(philo->monitor_mutex));
	}
	pthread_mutex_unlock(&(philo->monitor_mutex));
}

void	write_message(char type, t_philo *philo, unsigned long time)
{
	pthread_mutex_lock(philo->write_mutex);
	if (*(philo->should_stop) || (philo->dead && type != 'd'))
	{
		pthread_mutex_unlock(philo->write_mutex);
		return ;
	}
	if (type == 'e')
		printf(EATING, (time - philo->start), philo->id);
	if (type == 's')
		printf(SLEEPING, (time - philo->start), philo->id);
	if (type == 't')
		printf(THINKING, (time - philo->start), philo->id);
	if (type == 'f')
		printf(FORKING, (time - philo->start), philo->id);
	if (type == 'd')
	{
		printf(DIED, (time - philo->start), philo->id);
		*(philo->should_stop) = philo->id;
	}
	pthread_mutex_unlock(philo->write_mutex);
}

//returns a timestamp in milliseconds
unsigned long	gettime_in_ms(void)
{
	struct timeval	tv;
	int				tries;

	tries = 0;
	while (gettimeofday(&tv, NULL) == -1 && tries < 3)
		++tries;
	if (tries == 3)
		return (ULONG_MAX);
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
