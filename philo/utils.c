/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:26:37 by nraatika          #+#    #+#             */
/*   Updated: 2025/09/09 12:55:41 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	if (s == NULL)
		return (0);
	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}
