/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:32:32 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/23 12:28:35 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*temp;

	if (argc > 1)
	{
		printf("\n---\nreading file %s:\n", argv[1]);
		int file = open(argv[1], O_RDONLY);
		temp = get_next_line(file);
		printf("found line: %s", temp);
		while (temp)
		{
			free(temp);
			temp = get_next_line(file);
			if (temp)
				printf("found line: %s", temp);
		}
		free(temp);
		close(file);
	}
	else 
	{
		printf("reading from stdin\n");
		temp = get_next_line(0);
		while (!temp)
			temp = get_next_line(0);
		printf("found line: %s", temp);
		free(temp);
	}
	return (0);
}
