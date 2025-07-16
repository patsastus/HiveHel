/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:05:21 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/16 10:48:17 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

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
Contains flags and other values needed for the conversion

Conversion format string is of format
%[flags: '0', '#', ' ', '+' or '-'][width:non-zero integers]...
[precision: '.' optionally followed by integers]...
[conversion specifier:cspiuxX%]

int hash: '#' flag was passed, which changes output of hexadecimal 
conversions to be prepended with '0x' or '0X'

int minus:	'-' flag was passed, converted value is left adjusted. overrides 
'0' flag

int zero: '0' flag was passed. left pad with zero for numerical values, unless
flag '-' was passed or precision was defined

int space: ' ' flag was passed, leave a blank space in front of positive number

int plus: '+' tag was passed, all number outputs start with a sign (+ or -)

int precision: '.' flag was passed, with or without trailing digits that are 
read into precision.

int precision_value: gives the minimum number of digits to appear for 
d, i, u, x, X, or the maximum number of characters shown of a string.

e_conversion conv: which conversion type was specifieid

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
	int				precision_value;
	int				width;
	int				read;
}	t_flag;

int		ft_printf(const char *s, ...);
char	*ft_utoa(unsigned int u);
char	*ft_itoa_hex(unsigned long i);
t_flag	*make_flags_bonus(const char *s);
int		ft_convert_bonus(const char **s, va_list *ap);
int		write_char_bonus(char c, t_flag *flags);
int		write_hex_bonus(int i, t_flag *flags);
int		write_int_bonus(int i, t_flag *flags);
int		write_ptr_bonus(void *p, t_flag *flags);
int		write_str_bonus(char *s, t_flag *flags);
int		write_uint_bonus(unsigned int u, t_flag *flags);
char	*pad_c(char c, t_flag *flags);
char	*pad_s(char *s, t_flag *flags, int len);
char	*pad_zero(char *s, int n);
void	pad_sign(char **s, char c);

#endif
