/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:26:37 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/03 12:10:22 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	free_philo(t_philo *philo)
{
	if (!philo)
		return ;
	sem_close(philo->write);
	sem_close(philo->forks);
	sem_close(philo->death);
	sem_close(philo->fork_mutex);
	free(philo);
}

void	targeted_sleep(t_philo *philo, unsigned long target)
{
	unsigned long	temp;

	temp = gettime_in_ms();
	while (temp < target)
	{
		usleep(BLINK);
		temp = gettime_in_ms();
		if (temp - philo->last_meal > philo->time_to_die)
		{
			dying(philo, 0);
			return ;
		}
	}
}

//if write is of type DIED, don't repost write semaphor so no extra output made
void	write_message(char type, t_philo *philo, unsigned long time)
{
	const char	*msg[] = {"%u %d is eating\n", "%u %d is sleeping\n", \
"%u %d is thinking\n", "%u %d has taken a fork\n", "%u %d died\n"};

	sem_wait(philo->write);
	if (type == 'e')
		printf(msg[0], (time - philo->start), philo->id, philo->meals_eaten);
	if (type == 's')
		printf(msg[1], (time - philo->start), philo->id);
	if (type == 't')
		printf(msg[2], (time - philo->start), philo->id);
	if (type == 'f')
		printf(msg[3], (time - philo->start), philo->id);
	if (type == 'd')
		printf(msg[4], (time - philo->start), philo->id);
	if (type != 'd')
		sem_post(philo->write);
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
