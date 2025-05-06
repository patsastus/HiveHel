/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:32:21 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/06 09:37:33 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include "libft/libft.h"

t_flag	*make_flags(const char *s)
{
	t_flag	*flags;

	flags = ft_calloc(sizeof(t_flag), 1);
	if (!flags)
		return (NULL);
	if (*(s + 1) == 'c')
		flags->conv = CHAR;
	if (*(s + 1) == 's')
		flags->conv = STR;
	if (*(s + 1) == 'p')
		flags->conv = PTR;
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
		flags->conv = INT;
	if (*(s + 1) == 'u')
		flags->conv = UINT;
	if (*(s + 1) == 'x')
		flags->conv = LOX;
	if (*(s + 1) == 'X')
		flags->conv = HIX;
	if (*(s + 1) == '%')
		flags->conv = PER;
	return (flags);
}
