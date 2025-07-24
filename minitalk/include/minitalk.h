/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:19:54 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/23 11:08:37 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

extern volatile sig_atomic_t	g_handler_flag;
extern volatile sig_atomic_t	g_got_response;

#endif
