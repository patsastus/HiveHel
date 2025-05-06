/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:14:09 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/06 10:09:06 by nraatika         ###   ########.fr       */
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

/**
Contains flags that modify the conversion

int hash: '#' flag was passed, which changes output of hexadecimal 
conversions to be prepended with '0x'

int minus:	'-' flag was passed, converted value is left adjusted. overrides 
'0' flag

int zero: '0' flag was passed. left pad with zero for numerical values, unless
flag '-' was passed or precision was defined

int space: ' ' flag was passed, leave a blank space in front of positive number

int plus: '+' tag was passed, all number outputs start with a sign (+ or -)

int precision: '.' flag followed by decimal digit string. Gives the minimum
 number of digits to appear for d, i, u, x, X, or the maximum number of
 characters shown of a string.

e_conv conv: which conversion type was specifieid

int read:	how many characters were read by conversion

*/
typedef struct s_flag
{
	enum e_conv		conv;
	int				hash;
	int				minus;
	int				zero;
	int				space;
	int				plus;
	int				precision;
	int				width;
	int				read;
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
