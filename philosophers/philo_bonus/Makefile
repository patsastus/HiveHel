# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 09:57:26 by nraatika          #+#    #+#              #
#    Updated: 2025/10/06 12:46:54 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Binary
NAME		:= philo_bonus

## Directories
OBJ_DIR		:= objs

## Files
SRCS		:=	main.c parsing.c philosopher.c actions.c init.c utils.c
HEADER		:=	philosophers.h

OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

## Compiler config
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
CFLAGS		+= -O0 
RM			:= rm -f

LIBS		:= -pthread

$(NAME):		$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJ_DIR)/%.o:	%.c $(HEADER) | $(OBJ_DIR)  
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

all:			$(NAME)

clean:                                   
		$(RM) -r $(OBJ_DIR)
		                                         
fclean:			clean 
		$(RM) $(NAME)
	
re:				fclean all               

.PHONY:		all clean fclean re
