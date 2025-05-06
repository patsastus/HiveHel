/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:30:40 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/28 14:33:54 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	write_int(int i)
{
	char	*temp;
	int		ret;

	temp = ft_itoa(i);
	ret = (write(1, temp, ft_strlen(temp)));
	free(temp);
	return (ret);
}
