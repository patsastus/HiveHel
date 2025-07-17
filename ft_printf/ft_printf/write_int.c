/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:30:40 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:56:19 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	write_int(int i)
{
	char	*temp;
	int		ret;

	temp = ft_itoa(i);
	if (!temp)
		return (-1);
	ret = (write(1, temp, ft_strlen(temp)));
	free(temp);
	return (ret);
}
