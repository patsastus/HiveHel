/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:56:13 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/23 09:54:49 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# ifndef FLIST_SIZE
#  define FLIST_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

/*	buf 	contains the data, 
	index 	where to start reading (some data may have been used already)
	eof		index where eof was found when filling buffer, 
			or BUFFER_SIZE if fully filled
	used	has this struct been used already
*/
typedef struct s_data
{
	char	buf[BUFFER_SIZE];
	ssize_t	start;
	ssize_t	eof;
	char	used;
}	t_data;

char	*get_next_line(int fd);
ssize_t	read_until_line(t_data *d, char **s, int fd);
ssize_t	check_update_buffer(t_data *d, char **s);
char	*make_str(t_data *d, ssize_t size);
char	*handle_new_index(t_data *d, ssize_t index);

ssize_t	i_of_newline(char *s, ssize_t start, ssize_t buf);
char	*ft_strjoin(char *one, char *two, ssize_t len);
ssize_t	ft_strlen(char *s);
void	init_struct(t_data *d);

#endif
