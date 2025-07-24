/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:17:28 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/23 13:40:09 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>
#include <libft.h>

volatile sig_atomic_t	g_got_response;

static void	client_sig_handler(int signum)
{
	g_got_response = 1;
	if (signum == SIGUSR2)
		write(1, "Server ACKed full message received\n", 35);
}

static int	arg_checker(int argc, char **argv)
{
	const char	*error = "Wrong number of arguments. './client PID message'\n";
	const char	*pid_error = "Illegal PID\n";
	int			value;

	if (argc != 3)
	{
		write(1, error, ft_strlen(error));
		return (-1);
	}
	value = 0;
	while (value < (int)ft_strlen(argv[1]))
	{
		if (!(ft_isdigit(argv[1][value])))
		{
			write(1, pid_error, ft_strlen(pid_error));
			return (-1);
		}
		value++;
	}
	value = ft_atoi(argv[1]);
	return (value);
}

static void	transmit(int pid, char c)
{
	int	i;
	int	temp;

	i = 0;
	while (i < 8)
	{
		g_got_response = 0;
		if ((c >> i) & 1)
			temp = kill(pid, SIGUSR2);
		else
			temp = kill(pid, SIGUSR1);
		if (temp != -1)
			++i;
		else
		{
			write(2, "SEND ERR\n", 9);
			exit(1);
		}
		sleep(1);
		if (g_got_response == 0)
		{
			write(2, "NO ACK\n", 7);
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;
	const char			*pid_error = "Illegal PID\n";

	act.sa_handler = client_sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	pid = arg_checker(argc, argv);
	if (pid < 1 || kill(pid, 0) == -1)
	{
		write(1, pid_error, ft_strlen(pid_error));
		return (-1);
	}
	while (argv[2] && *argv[2] != '\0')
	{
		transmit(pid, *argv[2]);
		argv[2]++;
	}
	transmit(pid, '\0');
	return (0);
}
