/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:04:01 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:56:40 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	write_uint(unsigned int u)
{
	char	*temp;
	int		ret;

	temp = ft_utoa(u);
	if (!temp)
		return (-1);
	ret = (write(1, temp, ft_strlen(temp)));
	free(temp);
	return (ret);
}
