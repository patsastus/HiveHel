/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:26:23 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/16 15:56:43 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

#include <unistd.h>
#include <stdlib.h>

/*	buf 	contains the data, 
	index 	where to start reading (some data may have been used already)
	eof		index where eof was found when filling buffer, 
			or BUFFER_SIZE if fully filled
*/
typedef struct s_data
{
	char	*buf;
	ssize_t	start;
	ssize_t	eof;
}	t_data;

char	*get_next_line(int fd);
long	read_until_line(t_data *d, char **s, int fd);
long	check_update_buffer(t_data *d, char **s);
char	*make_str(t_data *d, long size);

long	i_of_newline(char *s, size_t start, size_t buf);
char	*ft_strjoin(char *one, char *two, ssize_t len);
size_t	ft_strlen(char *s);

#endif
