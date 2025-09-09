/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:35:31 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/09 13:43:23 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>

# define COUNT "incorrect number of arguments\n"
# define NUMERIC "numeric argument required\n"
# define OVERFLOW "int overflow when parsing argument\n"

typedef struct	s_philo
{
	pthread_t		thread;
	pthread_mutex_t	forks[2];
	int				id;
	int				last_meal_time;
	int				meals_eaten;
	char			is_dead;
	char			current_action;
}	t_philo;

typedef struct	s_table
{
	t_philo			*philos;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*alive_check_mutex;
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				required_meals;
}	t_table;

//utils.c
size_t	ft_strlen(const char *s);

//philosopher.c
void	init_philosopher(int id, int current_time, t_philo *philo);
void	take_fork(t_philo *philo);
void	release_fork(t_philo *philo);
void	loop_philosopher(t_philo *philo);

//parsing.c
t_table	*parse_to_table(int argc, char **argv);

#endif
