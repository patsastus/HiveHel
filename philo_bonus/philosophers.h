/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:35:31 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/03 12:25:23 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <fcntl.h>
# include <semaphore.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>

# define COUNT "incorrect number of arguments\n"
# define NUMERIC "numeric argument required\n"
# define OVERFLOW "int overflow when parsing argument\n"
# define FORKS_SEM_NAME "/philo_forks"
# define WRITE_SEM_NAME "/philo_write"
# define DEATH_SEM_NAME "/philo_death"
# define FORK_MUTEX "/philo_mutex"
# define BLINK 100
# define MS 1000

typedef struct s_philo
{
	int				pid;
	sem_t			*fork_mutex;
	sem_t			*forks;
	sem_t			*write;
	sem_t			*death;
	unsigned int	id;
	unsigned long	start;
	unsigned long	last_meal;
	unsigned int	meals_eaten;
	unsigned int	meals_goal;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	char			current_action;
	char			dead;
	char			should_stop;
}	t_philo;

typedef struct s_table
{
	pthread_t		monitor;
	t_philo			**philos;
	sem_t			*fork_mutex;
	sem_t			*forks;
	sem_t			*write;
	sem_t			*death;
	unsigned int	count;
	unsigned long	start;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	required_meals;
	char			error_flag;
}	t_table;

//utils.c
size_t			ft_strlen(const char *s);
unsigned long	gettime_in_ms(void);
void			write_message(char type, t_philo *philo, unsigned long time);
void			targeted_sleep(t_philo *philo, unsigned long target);
void			free_philo(t_philo *philo);

//philosopher.c
t_philo			*init_philosopher(unsigned int id, unsigned long start_time, \
t_table *table);
void			take_forks(t_philo *philo);
void			release_forks(t_philo *philo);
void			loop_philo(void *input);

//init.c
void			init_philos(t_table *table, unsigned long start);
void			init_semaphores(t_table *table);

//actions.c
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			dying(t_philo *philo, int silent);

//parsing.c
t_table			*parse_to_table(int argc, char **argv);

//main.c
void			free_table(t_table *table);

#endif
