/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:17:28 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/15 13:46:48 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk_bonus.h>
#include <libft.h>

volatile sig_atomic_t	g_client;

static void	init_handler(struct sigaction *act)
{
	act->sa_handler = signal_handler_client;
	sigemptyset(&(act->sa_mask));
	act->sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	const char			*error = "Wrong number of arguments or empty string\n";
	const char			*pid_error = "Illegal PID\n";
	int					pid;

	g_client = 0;
	if (argc != 3 || ft_strlen(argv[2]) < 1)
	{
		write(1, error, ft_strlen(error));
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		write(1, pid_error, ft_strlen(pid_error));
		return (1);
	}
	init_handler(&act);
	send_message(pid, argv[2]);
	return (0);
}

void	signal_handler_client(int signum)
{
	if (!g_client)
	{
		g_client = 1;
		if (signum == SIGUSR1)
			g_client = SIGUSR1;
		if (signum == SIGUSR2)
			g_client = SIGUSR2;
	}
}

void	send_message(int pid, char *message)
{
	int	char_bit;
	int	response;

	while (message && *message)
	{
		if (*message >= 32 && *message <= 127)
		{
			char_bit = 0;
			while (char_bit < 8)
			{
				if (*message & (1 << char_bit))
					response = transmit(pid, SIGUSR2);
				else
					response = transmit(pid, SIGUSR1);
				if (!response)
					exit(1);
				++char_bit;
			}
		}
		message++;
	}
	char_bit = 0;
	while (++char_bit <= 8)
		transmit(pid, SIGUSR1);
}

int	transmit(int pid, int signal)
{
	int	attempts;

	attempts = 0;
	while (attempts < 5)
	{
		kill(pid, signal);
		g_client = 0;
		usleep(SLEEP_TIME * 5);
		if (g_client == signal)
			return (1);
		else if (g_client == 0)
		{
			attempts++;
			continue ;
		}
		else
			return (0);
	}
	return (0);
}
