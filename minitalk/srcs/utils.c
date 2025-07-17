/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:21:16 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 13:20:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>
#include <libft.h>

static void	reset(unsigned char *array)
{
	array[0] = 0;
	array[1] = 0;
	array[2] = 1;
}

static void	print_clear(char **str, unsigned char *array)
{
	write(1, *str, ft_strlen(*str));
	if (array[1] == 0)
	{
		write(1, "\n", 1);
		free(*str);
		reset(array);
		*str = NULL;
	}
	else
	{
		write(2, "\nunexpected char\n", 17);
		free_and_exit(*str, 5);
	}
}

void	free_and_exit(void *p, int status)
{
	free(p);
	exit(status);
}

void	append(char **str, unsigned char *array)
{
	char	*temp;
	size_t	size;

	if (array[1] == 0 || !(array[1] >= 32 && array[1] <= 127))
	{
		print_clear(str, array);
		return ;
	}
	size = ft_strlen(*str);
	temp = malloc((size + 2) * sizeof(char));
	if (!temp)
		free_and_exit(*str, 1);
	ft_memcpy(temp, *str, size);
	temp[size] = (char)array[1];
	temp[size + 1] = '\0';
	free(*str);
	*str = temp;
	reset(array);
}
