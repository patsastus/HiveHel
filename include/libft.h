/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:33:20 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/25 11:47:53 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//ft_printf
typedef enum e_printf_conv
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
}	t_printf_conv;

typedef struct s_printf_flag
{
	enum e_printf_conv	conv;
	int					hash;
	int					minus;
	int					zero;
	int					space;
	int					plus;
	int					precision;
	int					precision_value;
	int					width;
	int					read;
}	t_printf_flag;

//libft
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(char c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
//bonus
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),\
					void (*del)(void *));

//minmax.c
int				ft_min(int a, int b);
int				ft_max(int a, int b);

//ft_printf
int				ft_printf(const char *s, ...);
char			*ft_utoa(unsigned int u);
char			*ft_itoa_hex(unsigned long i);
t_printf_flag	*make_flags(const char *s);
int				ft_printf_convert(const char **s, va_list *ap);
int				write_char(char c, t_printf_flag *flags);
int				write_hex(int i, t_printf_flag *flags);
int				write_int(int i, t_printf_flag *flags);
int				write_ptr(void *p, t_printf_flag *flags);
int				write_str(char *s, t_printf_flag *flags);
int				write_uint(unsigned int u, t_printf_flag *flags);
char			*pad_c(char c, t_printf_flag *flags);
char			*pad_s(char *s, t_printf_flag *flags, int len);
char			*pad_zero(char *s, int n);
void			pad_sign(char **s, char c);

#endif
