# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 11:45:38 by nraatika          #+#    #+#              #
#    Updated: 2025/04/25 12:42:39 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=ft_atoi.c		ft_calloc.c		ft_isalpha.c	ft_isdigit.c\
		ft_memchr.c		ft_memcpy.c		ft_memset.c		ft_strdup.c\
		ft_strlcpy.c	ft_strncmp.c	ft_strrchr.c 	ft_toupper.c\
		ft_bzero.c 		ft_isalnum.c 	ft_isascii.c	ft_isprint.c\
	 	ft_memcmp.c		ft_memmove.c 	ft_strchr.c 	ft_strlcat.c\
		ft_strlen.c 	ft_strnstr.c	ft_tolower.c 	ft_substr.c\
	 	ft_strjoin.c	ft_strtrim.c 	ft_split.c 		ft_itoa.c\
		ft_strmapi.c 	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c

B_SRCS	=ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstsize_bonus.c\
		ft_lstlast_bonus.c	ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c	ft_lstiter_bonus.c		ft_lstmap_bonus.c

HEADER	=libft.h

OBJS	=$(SRCS:%.c=%.o)
B_OBJS	=$(B_SRCS:%.c=%.o)
CC		=cc
CFLAGS 	=-Wall -Wextra -Werror
AR		=ar rcs
RM		=rm -f
NAME	=libft.a
BONUS	=.bonus

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

$(OBJS:%.o):	$(SRCS:%.c) $(HEADER)
				$(CC) $(CFLAGS) $(HEADER)-c $< -o $@

$(B_OBJS:%.o):	$(B_SRCS:%.c) $(HEADER)
				$(CC) $(CFLAGS) $(HEADER)-c $< -o $@

clean:
				$(RM) $(OBJS) $(B_OBJS) 

fclean:			clean
				$(RM) $(NAME) $(BONUS)

re:				fclean all

bonus:			$(BONUS)

$(BONUS):		$(NAME) $(B_OBJS)
				$(AR) $(NAME) $(B_OBJS)
				touch $(BONUS)

.PHONY:			all clean fclean re	bonus
