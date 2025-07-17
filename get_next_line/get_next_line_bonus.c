/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:55:27 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/19 17:08:18 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*ret;
	static t_data	files[FLIST_SIZE];
	long			tmp;

	ret = NULL;
	if (fd >= FLIST_SIZE || fd < 0)
		return (NULL);
	tmp = check_update_buffer(&(files[fd]), &ret);
	if (tmp >= 0)
	{
		if ((files[fd]).eof >= tmp)
			return (ret);
		if ((files[fd]).eof <= (files[fd]).start)
			return (free(ret), NULL);
	}
	if (tmp == -1)
		tmp = read_until_line(&(files[fd]), &ret, fd);
	if ((files[fd]).eof == -1 && ft_strlen(ret) == 0)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

ssize_t	read_until_line(t_data *d, char **s, int fd)
{
	ssize_t	rd;
	ssize_t	in;

	rd = 0;
	while (d->start <= d->eof)
	{
		rd = read(fd, d->buf, BUFFER_SIZE);
		if (rd <= 0)
		{
			d->eof = -1;
			break ;
		}
		if (rd < BUFFER_SIZE)
			d->eof = rd - 1;
		else
			d->eof = BUFFER_SIZE;
		d->start = 0;
		in = check_update_buffer(d, s);
		if (in == -2)
			return (-2);
		if (in != -1)
			break ;
	}
	return (rd);
}

/*	
	Checks if newline in buf, writes until newline or end of buffer into ret, 
	allocating necessary memory. updates d->start if a newline was in buffer
	returns:
		-2		if malloc failed
		-1 		if no newline or eof found
		i > 0	wrote something up to newline at index i-1
		
*/
ssize_t	check_update_buffer(t_data *d, char **s)
{
	ssize_t	new_index;
	char	*temp;
	char	*new;

	if (!(d->used))
		init_struct(d);
	if (d->eof < d->start)
		return (0);
	if (d->start == BUFFER_SIZE)
		return (-1);
	new_index = i_of_newline(d->buf, d->start, d->eof);
	temp = handle_new_index(d, new_index);
	if (!temp)
		return (-2);
	new = ft_strjoin(*s, temp, ft_strlen(temp));
	free(temp);
	if (!new)
		return (-2);
	free(*s);
	*s = new;
	return (new_index);
}

/*
*	allocates memory for and copies data into string
*/
char	*make_str(t_data *d, ssize_t size)
{
	char	*s;
	ssize_t	len;
	ssize_t	i;

	if (d->eof < size)
		size = d->eof + 1;
	len = size - d->start;
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = (d->buf)[d->start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*handle_new_index(t_data *d, ssize_t index)
{
	char	*temp;

	if (index == -1 && d->eof == BUFFER_SIZE)
	{
		temp = make_str(d, BUFFER_SIZE);
		d->start = BUFFER_SIZE;
	}
	else
	{
		if (index == -1)
			index = d->eof;
		temp = make_str(d, index + 1);
		d->start = index + 1;
	}
	return (temp);
}
