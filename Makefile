# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 09:57:26 by nraatika          #+#    #+#              #
#    Updated: 2025/09/18 12:23:24 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Binary
NAME		:= philo

## Directories
SRC_DIR		:= philo
OBJ_DIR		:= objs
INC_DIR		:= philo

## Files
SRCS		:=	main.c parsing.c philosopher.c actions.c monitor.c utils.c
HEADER		:=	philosophers.h

OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
HEADERS		:= $(addprefix $(INC_DIR)/, $(HEADER))

## Compiler config
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
CFLAGS		+= -O0
RM			:= rm -f

INC			:= -I$(INC_DIR)
LIBS		:= -pthread


$(SRC_DIR)/$(NAME):		$(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBS) -o $@

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c $(INC_DIR)/$(HEADER) | $(OBJ_DIR)  
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

all:			$(SRC_DIR)/$(NAME)

clean:                                   
		$(RM) -r $(OBJ_DIR)
	                                         
fclean:			clean 
		$(RM) $(SRC_DIR)/$(NAME)
	
re:				fclean all               

.PHONY:		all clean fclean re
