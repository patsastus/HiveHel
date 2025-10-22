/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:26:37 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/15 10:38:28 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

/*
	frees the table struct associated with a child process, where only the philo
	for that loop has semaphores open
*/
void	free_philo(t_table *table)
{
	int	i;

	if (!table)
		return ;
	i = -1;
	while (++i < (int)table->count)
	{
		if (i == table->loop_index)
		{
			sem_close(table->philos[i]->write);
			sem_close(table->philos[i]->forks);
			sem_close(table->philos[i]->death);
			sem_close(table->philos[i]->fork_mutex);
			sem_close(table->philos[i]->self_mutex);
			sem_unlink(table->philos[i]->self_mutex_name);
			table->philos[i]->should_stop = 1;
			usleep(MS * 2);
		}
		free(table->philos[i]);
	}
	free(table->philos);
	free(table);
}

void	targeted_sleep(t_philo *philo, unsigned long target)
{
	unsigned long	temp;

	temp = gettime_in_ms();
	while (temp < target && !philo->dead)
	{
		usleep(BLINK);
		temp = gettime_in_ms();
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
