/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:53:27 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/17 15:59:41 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	contains_nondigits(char *str)
{
	while (str && *str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		++str;
	}
	return (0);
}

static unsigned int	checked_atoi(char *input, char *flag)
{
	long	val;

	if (contains_nondigits(input))
	{
		*flag = 1;
		return (0);
	}
	val = 0;
	while (*input && val * 1000 < UINT_MAX)
	{
		val *= 10;
		val += *input - '0';
		++input;
	}
	if (val * 1000 >= UINT_MAX)
		*flag = 2;
	return ((unsigned int)val);
}

static t_table	*parse_input(int argc, char **argv, char *flag)
{
	t_table			*table;
	int				index;
	unsigned int	params[5];

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	index = 0;
	while (++index < argc && !(*flag))
		params[index - 1] = checked_atoi(argv[index], flag);
	if (*flag)
		return (table);
	pthread_mutex_init(&(table->write_mutex), NULL);
	table->count = params[0];
	table->time_to_die = params[1];
	table->time_to_eat = params[2];
	table->time_to_sleep = params[3];
	if (argc == 6)
		table->required_meals = params[4];
	else
		table->required_meals = UINT_MAX;
	return (table);
}

t_table	*parse_to_table(int argc, char **argv)
{
	t_table		*output;
	char		flag;

	flag = 0;
	if (argc < 5 || argc > 6)
	{
		write(2, COUNT, ft_strlen(COUNT));
		return (NULL);
	}
	output = parse_input(argc, argv, &flag);
	if (!flag)
		return (output);
	else
	{
		free(output);
		if (flag == 1)
			write(2, NUMERIC, ft_strlen(NUMERIC));
		if (flag == 2)
			write(2, OVERFLOW, ft_strlen(OVERFLOW));
		return (NULL);
	}
}
