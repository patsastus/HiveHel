/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:03:52 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 13:18:37 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>
#include <libft.h>

volatile sig_atomic_t	g_handler_flag;

int	main(void)
{
	struct sigaction	act;

	g_handler_flag = 0;
	act.sa_handler = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	print_pid();
	while (1)
		pause();
}

void	signal_handler(int signum)
{
	static unsigned char	vars[3] = {0, 0, 1};
	static char				*text = NULL;

	if (g_handler_flag)
	{
		write(2, "SIG COLL", 8);
		return ;
	}
	g_handler_flag = 1;
	if (!text)
		text = ft_strdup("");
	if (!text || signum == SIGINT)
		free_and_exit((void *)text, SIGINT);
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		vars[0]++;
		if (signum == SIGUSR2)
			vars[1] += vars[2];
		vars[2] *= 2;
	}
	if (vars[0] == 8)
	{
		append(&text, vars);
	}
	g_handler_flag = 0;
}

void	print_pid(void)
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
