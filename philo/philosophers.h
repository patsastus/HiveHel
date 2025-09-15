/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:35:31 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/12 14:27:46 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdatomic.h>
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
	unsigned long	start;
	atomic_ulong	last_meal_time;
	atomic_int		meals_eaten;
	unsigned int	meals_goal;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	atomic_char		current_action;
	atomic_char		dead;
}	t_philo;

typedef struct s_table
{
	t_philo			**philos;
	pthread_t		monitor;
	pthread_mutex_t	write_mutex;
	unsigned int	count;
	unsigned long	start_time;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				required_meals;
	char			someone_died;
	char			error_flag;
}	t_table;

//utils.c
size_t			ft_strlen(const char *s);
unsigned long	gettime_in_ms(void);
void			free_table(t_table *table);

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
void			dying(t_philo *philo);

//parsing.c
t_table			*parse_to_table(int argc, char **argv);

#endif
