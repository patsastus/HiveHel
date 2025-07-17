/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:17:28 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 14:37:17 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>
#include <libft.h>

int	main(int argc, char **argv)
{
	const char	*error = "Wrong number of arguments or empty string\n";
	const char	*pid_error = "Illegal PID\n";
	int			pid;

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
	send_message(pid, argv[2]);
	return (0);
}

void	send_message(int pid, char *message)
{
	while (message && *message)
	{
		if (*message >= 32 && *message <= 127)
			transmit(pid, *message);
		message++;
	}
	transmit(pid, '\0');
}

void	transmit(int pid, char c)
{
	int	i;
	int temp;
	int	tries;

	i = 0;
	tries = 0;
	while (i < 8 && tries < 5)
	{
		if (c & (1 << i))
			temp = kill(pid, SIGUSR2);
		else
			temp = kill(pid, SIGUSR1);
		if (temp != -1)
		{
			tries = 0;
			++i;
		}
		else
		{
			write(2, "SEND ERR", 8);
			tries++;
		}
		usleep(SLEEP_TIME);
	}
}
