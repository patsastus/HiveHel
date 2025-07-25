# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 11:45:38 by nraatika          #+#    #+#              #
#    Updated: 2025/07/25 14:59:24 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		:=libft.a

SRC_DIR		:= srcs
OBJ_DIR		:= objs
INC_DIR		:= include

#libft
SRCS		:=ft_atoi.c		ft_calloc.c		ft_isalpha.c	ft_isdigit.c\
			ft_memchr.c		ft_memcpy.c		ft_memset.c		ft_strdup.c\
			ft_strlcpy.c	ft_strncmp.c	ft_strrchr.c 	ft_toupper.c\
			ft_bzero.c 		ft_isalnum.c 	ft_isascii.c	ft_isprint.c\
	 		ft_memcmp.c		ft_memmove.c 	ft_strchr.c 	ft_strlcat.c\
			ft_strlen.c 	ft_strnstr.c	ft_tolower.c 	ft_substr.c\
	 		ft_strjoin.c	ft_strtrim.c 	ft_split.c 		ft_itoa.c\
			ft_strmapi.c 	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c	minmax.c		ft_isspace.c\
			ft_lstnew.c		ft_lstadd_front.c				ft_lstsize.c\
			ft_lstlast.c	ft_lstadd_back.c				ft_lstdelone.c\
			ft_lstclear.c	ft_lstiter.c					ft_lstmap.c

#ft_printf
SRCS		+=make_flags.c	ft_convert.c	ft_printf.c		write_char.c\
			write_str.c		write_ptr.c		write_int.c		write_uint.c\
			write_hex.c		padding.c		ft_itoa_hex.c	ft_utoa.c

#get_next_line


HEADER		:=libft.h
INC			:= -I./$(INC_DIR) 

OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC		:=cc
CFLAGS 	:=-Wall -Wextra -Werror -g
AR		:=ar rcs
RM		:=rm -f

all:			$(NAME)

$(NAME):		$(OBJS) $(INC_DIR)/$(HEADER)
				$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INC_DIR)/$(HEADER) | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INC) $(LIBS) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
