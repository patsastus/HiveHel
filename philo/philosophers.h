/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:35:31 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/18 12:03:54 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdatomic.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <stdio.h>

# define COUNT "incorrect number of arguments\n"
# define NUMERIC "numeric argument required\n"
# define OVERFLOW "int overflow when parsing argument\n"
# define BLINK 100
# define MS 1000

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	monitor_mutex;
	pthread_mutex_t	own_fork;
	pthread_mutex_t	*other_fork;
	pthread_mutex_t	*write_mutex;
	unsigned int	id;
	atomic_ulong	start;
	atomic_ulong	last_meal;
	atomic_uint		meals_eaten;
	atomic_uint		meals_goal;
	atomic_uint		time_to_die;
	atomic_uint		time_to_eat;
	atomic_uint		time_to_sleep;
	atomic_char		current_action;
	atomic_char		dead;
	atomic_char		holding;
}	t_philo;

typedef struct s_table
{
	t_philo			**philos;
	pthread_t		monitor;
	pthread_mutex_t	write_mutex;
	unsigned int	count;
	unsigned long	start;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	required_meals;
	atomic_char		someone_died;
	char			error_flag;
}	t_table;

//utils.c
size_t			ft_strlen(const char *s);
unsigned long	gettime_in_ms(void);
void			write_message(char type, t_philo *philo, unsigned long time);
void			targeted_sleep(t_philo *philo, unsigned long target);

//philosopher.c
t_philo			*init_philosopher(unsigned int id, unsigned long start_time, \
t_table *table);
void			take_forks(t_philo *philo);
void			release_forks(t_philo *philo, int silent);
void			*loop_philo(void *input);

//monitor.c
void			*monitor(void *input);

//actions.c
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			dying(t_philo *philo, int silent);

//parsing.c
t_table			*parse_to_table(int argc, char **argv);

//main.c
void			free_table(t_table *table, int monitor, int num_philos);

#endif
