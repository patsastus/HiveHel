/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:04:01 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/28 16:23:52 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	write_uint(unsigned int u)
{
	char	*temp;
	int		ret;

	temp = ft_utoa(u);
	ret = (write(1, temp, ft_strlen(temp)));
	free(temp);
	return (ret);
}
