/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:26:14 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/16 15:58:08 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*ret;
	static t_data	d = {(char *)NULL, -1, -1};
	long			tmp;
	
	ret = NULL;
	tmp = check_update_buffer(&d, &ret);
	if (tmp >= 0)
	{
		if (d.eof == (BUFFER_SIZE))
			return (ret);
		if (d.eof <= d.start)
			return (NULL);
	}
	if (tmp == -1) //no newline found in buffer
		tmp = read_until_line(&d, &ret, fd);
	return (ret);
}

long	read_until_line(t_data *d, char **s, int fd)
{
	ssize_t	rd;
	ssize_t	in;

	free((d->buf));
	d->buf = malloc((BUFFER_SIZE) * sizeof(char));
	if (!(d->buf))
		return (-2);
	while (fd > -1)
	{
		rd = read(fd, d->buf, (BUFFER_SIZE));
		if (rd <= 0)
			break;
		if (rd < (BUFFER_SIZE))
			d->eof = rd - 1;
		else
			d->eof = (BUFFER_SIZE);
		d->start = 0;
		in = check_update_buffer(d, s);
		if (in == -2)
			return (-2);
		if (in != -1)
			break;
	}
	return (rd);
}

/*	
	Checks if newline in buf, writes until newline or end of buffer into ret, 
	allocating necessary memory. updates start
	returns:
		-2		if malloc failed
		-1 		if no newline or eof found, full buffer written to s
		i >= 0	wrote something up to newline at index i
*/
long	check_update_buffer(t_data *d, char **s)
{
	long	new_in;
	char	*temp;
	char	*new;

	if (!(d->buf))
		return (-1);
	new_in = i_of_newline(d->buf, d->start, d->eof);
	if (new_in == -1)
	{
		temp = make_str(d, (BUFFER_SIZE));
		d->start = (BUFFER_SIZE);
	}
	else
	{
		temp = make_str(d, new_in + 1);
		d->start = new_in + 1;
	}
	if (!temp)
		return (-2);
	new = ft_strjoin(*s, temp, ft_strlen(temp));
	free(temp);
	if (!new)
		return (-2);
	free(*s);
	*s = new;
	return (new_in);
}

/*
*	allocates memory for and copies data into string
*/
char	*make_str(t_data *d, long size)
{
	char	*s;
	size_t	len;
	size_t	i;
	
	len = size - d->start;
	if (d->eof < BUFFER_SIZE)
		len = d->eof - d->start;
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
