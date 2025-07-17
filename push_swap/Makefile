# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 13:51:50 by nraatika          #+#    #+#              #
#    Updated: 2025/06/26 17:55:36 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

SRC_DIR		:= srcs
OBJ_DIR		:= objs
INC_DIR		:= include

SRCS		:=	main.c	list.c	sort.c	utils.c	init.c	moves_rotates.c\
				moves_push_swap.c moves_doubles.c list_utils.c sort_utils.c\
				sort_bucket.c
HEADER		:=	push_swap.h

OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g 
RM			:= rm -f

LIBFT_DIR	:= ./libft
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBFT_H		:= $(LIBFT_DIR)/libft.h

INC			:= -I./$(INC_DIR) -I$(LIBFT_DIR)
LIBS		:= -L$(LIBFT_DIR) -lft

$(NAME):	$(OBJS) $(INC_DIR)/$(HEADER) $(LIBFT)
		$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c $(INC_DIR)/$(HEADER) $(LIBFT) | $(OBJ_DIR)  
		$(CC) $(CFLAGS) $(INC) -c $< -o $@
:wa

$(LIBFT):		
		$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

all:			$(NAME)

debug:			$(DEBUG)

clean:                                   
		$(RM) $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean
                                         
fclean:			clean 
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:				fclean all               

.PHONY:		all clean fclean re
