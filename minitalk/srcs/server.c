/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:03:52 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/24 10:30:54 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>
#include <libft.h>

volatile sig_atomic_t	g_handler_flag;

static void	append(char c)
{
	static char		text[BUFFER_SIZE];
	static size_t	index = 0;

	text[index++] = c;
	if (c == '\0' || index == BUFFER_SIZE)
	{
		if (c == '\0')
			--index;
		write(1, text, index);
		if (c == '\0')
			write(1, "\n", 1);
		index = 0;
	}
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	character = 0;
	static int	index = 0;

	(void)context;
	if (g_handler_flag)
	{
		write(2, "handler collision\n", 17);
		return ;
	}
	g_handler_flag = 1;
	if (signum == SIGUSR2)
		character = character | (1 << index);
	index++;
	if (index == 8)
	{
		append(character);
		character = 0;
		index = 0;
	}
	g_handler_flag = 0;
	if (kill(info->si_pid, SIGUSR1) == -1)
		write(2, "ack error\n", 10);
}

static void	print_pid(void)
{
	pid_t	pid;
	char	*str;

	pid = getpid();
	str = ft_itoa(pid);
	if (str)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
	}
}

int	main(void)
{
	struct sigaction	act;

	g_handler_flag = 0;
	act.sa_sigaction = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_NODEFER | SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		exit(1);
	print_pid();
	while (1)
		pause();
}
