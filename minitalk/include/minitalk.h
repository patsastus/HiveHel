/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:19:54 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/15 12:01:37 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# ifndef SLEEP_TIME
#  define SLEEP_TIME 150
# endif

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

extern volatile sig_atomic_t	g_handler_flag;

//server.c
void	print_pid(void);
void	signal_handler(int signum);
void	free_and_exit(void *p, int status);

//client.c
void	append(char **str, unsigned char *array);
void	send_message(int pid, char *message);
void	transmit(int pid, char c);

#endif
