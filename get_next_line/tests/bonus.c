/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:59:24 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/23 12:18:02 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*temp;
	int		i;
	int		files[argc - 1];
	int		alldone = 0;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			printf("\nopening file %s:\n", argv[i]);
			files[i - 1] = open(argv[i], O_RDONLY);
			i++;
		}
		
		while(!alldone)
		{
			i = 0;
			alldone = 1;
			while (i < argc -1)
			{
				temp = get_next_line(files[i]);
				if (temp)
				{
					alldone = 0;
					printf("found line: %s in file %s\n", temp, argv[i + 1]);
					free(temp);
				}
				i++;
			}
		}
		i = 0;
		while (i < argc - 1)
		{
			close(files[i]);
			i++;
		}
	}
	return (0);
}
