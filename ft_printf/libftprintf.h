/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:14:09 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/08 16:37:17 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_conv
{
	ERR,
	CHAR,
	STR,
	PTR,
	INT,
	UINT,
	LOX,
	HIX,
	PER
}	t_conv;

/*
e_conv conv: which conversion type was specified
*/
typedef struct s_flag
{
	enum e_conv		conv;
}	t_flag;

int		ft_printf(const char *s, ...);
int		ft_convert(const char *s, va_list *ap);
t_flag	*make_flags(const char *s);
int		write_char(char c);
int		write_str(char *s);
int		write_ptr(void *p);
int		write_int(int i);
int		write_uint(unsigned int u);
int		write_hex(int i, int upper);
char	*ft_utoa(unsigned int u);
char	*ft_itoa_hex(unsigned long u);

#endif
