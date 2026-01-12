/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:34:30 by nraatika          #+#    #+#             */
/*   Updated: 2025/10/15 11:32:04 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

/*
	Loops through the children, and sends SIGKILL to any process that exists
*/
static void	kill_the_children(t_table *table)
{
	int	i;
	int	pid;

	table->error_flag = 'd';
	i = -1;
	while (++i < (int)table->count)
	{
		pid = table->philos[i]->pid;
		if (pid > 0 && waitpid(pid, NULL, WNOHANG) == 0)
			kill(pid, SIGKILL);
	}
	return ;
}

/*
	Waits for any child to exit, reacts to exit status: if philosopher exited 
	with return value != 0, kill all remaining child processes
*/
static int	wait_for_children(t_table *table)
{
	int	status;
	int	done_count;
	int	value;

	value = 0;
	done_count = 0;
	if (table->error_flag)
	{
		kill_the_children(table);
		return (1);
	}
	while (done_count < (int)table->count)
	{
		if (waitpid(-1, &status, 0) == -1)
			break ;
		++done_count;
		if (WIFEXITED(status))
			value += WEXITSTATUS(status);
		if (WIFSIGNALED(status))
			value += 1;
		if (value > 0)
			kill_the_children(table);
	}
	return (value);
}

static int	run_table(t_table *table)
{
	unsigned int	i;
	t_philo			*philo;

	i = -1;
	while (++i < table->count && !table->error_flag)
	{
		table->philos[i]->pid = fork();
		if (table->philos[i]->pid == 0)
		{
			philo = table->philos[i];
			table->loop_index = i;
			init_philo_semaphores(philo);
			if (philo->self_mutex == SEM_FAILED || philo->forks == SEM_FAILED \
|| philo->write == SEM_FAILED || philo->death == SEM_FAILED || \
philo->fork_mutex == SEM_FAILED)
			{
				free_philo(table);
				exit(1);
			}
			loop_philo(table);
		}
		if (table->philos[i]->pid == -1)
			table->error_flag = 4 + i;
	}
	return (wait_for_children(table));
}

void	free_table(t_table *table)
{
	unsigned int	i;

	i = -1;
	while (++i < table->count && table->philos)
		free(table->philos[i]);
	free(table->philos);
	sem_close(table->forks);
	sem_close(table->write);
	sem_close(table->death);
	sem_close(table->fork_mutex);
	sem_unlink(FORKS_SEM_NAME);
	sem_unlink(WRITE_SEM_NAME);
	sem_unlink(DEATH_SEM_NAME);
	sem_unlink(FORK_MUTEX);
	free(table);
}

int	main(int argc, char **argv)
{
	t_table			*table;
	unsigned long	time;
	int				value;

	value = 1;
	table = parse_to_table(argc, argv);
	if (!table)
		return (value);
	time = gettime_in_ms();
	if (time == ULONG_MAX || table->count == 0 || table->count > 200)
	{
		free_table(table);
		return (value);
	}
	init_philos(table, time);
	init_semaphores(table);
	if (!(table->error_flag))
	{
		value = run_table(table);
		sem_post(table->death);
	}
	free_table(table);
	return (value);
}
