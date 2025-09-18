/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:26:37 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/18 11:50:00 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	targeted_sleep(t_philo *philo, unsigned long target)
{
	unsigned long	temp;

	(void)philo;
	temp = gettime_in_ms();
	while (temp != ULONG_MAX && temp < target)
	{
		usleep(BLINK);
		temp = gettime_in_ms();
	}
}

void	write_message(char type, t_philo *philo, unsigned long time)
{
	const char	*msg[] = {"%u %d is eating meal %d\n", "%u %d is sleeping\n", \
"%u %d is thinking\n", "%u %d has taken fork %d\n", "%u %d has released \
forks\n", "%u %d died\n"};

	pthread_mutex_lock(philo->write_mutex);
	if (type == 'e')
		printf(msg[0], (time - philo->start), philo->id, philo->meals_eaten);
	if (type == 's')
		printf(msg[1], (time - philo->start), philo->id);
	if (type == 't')
		printf(msg[2], (time - philo->start), philo->id);
	if (type == 'f')
	{
		if (philo->id % 2)
			printf(msg[3], (time - philo->start), philo->id, philo->id - 1);
		printf(msg[3], (time - philo->start), philo->id, philo->id);
		if (!(philo->id % 2))
			printf(msg[3], (time - philo->start), philo->id, philo->id - 1);
	}
	if (type == 'r')
		printf(msg[4], (time - philo->start), philo->id);
	if (type == 'd')
		printf(msg[5], (time - philo->start), philo->id);
	pthread_mutex_unlock(philo->write_mutex);
}

//returns a timestamp in milliseconds
unsigned long	gettime_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
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
