/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:19:54 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/15 13:48:12 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# ifndef SLEEP_TIME
#  define SLEEP_TIME 150
# endif

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

extern volatile sig_atomic_t	g_server;
extern volatile sig_atomic_t	g_client;

//server.c
void	print_pid(void);
void	signal_handler_server(int signum, siginfo_t *info, void *context);
void	free_and_exit(void *p, int status);

//client.c
void	append(char **str, unsigned char *array);
void	send_message(int pid, char *message);
int		transmit(int pid, int signal);
void	signal_handler_client(int signum);

#endif
