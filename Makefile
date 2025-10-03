# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 09:57:26 by nraatika          #+#    #+#              #
#    Updated: 2025/10/03 10:14:01 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Binary
NAME		:= philo
BONUS		:= philo_bonus

## Directories
SRC_DIR		:= philo
BONUS_DIR	:= philo_bonus
OBJ_DIR		:= objs
BONUS_O_DIR	:= bonus_objs
INC_DIR		:= philo
BONUS_I_DIR	:= philo_bonus

## Files
SRCS		:=	main.c parsing.c philosopher.c actions.c monitor.c utils.c
B_SRCS		:=	main.c parsing.c philosopher.c actions.c init.c utils.c
HEADER		:=	philosophers.h

OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
B_OBJS		:= $(addprefix $(BONUS_O_DIR)/, $(B_SRCS:.c=.o))
HEADERS		:= $(addprefix $(INC_DIR)/, $(HEADER))
B_HEADERS	:= $(addprefix $(BONUS_I_DIR)/, $(HEADER))


## Compiler config
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
CFLAGS		+= -O0 
RM			:= rm -f

INC			:= -I$(INC_DIR)
B_INC		:= -I$(BONUS_I_DIR)
LIBS		:= -pthread

$(SRC_DIR)/$(NAME):		$(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBS) -o $@

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c $(INC_DIR)/$(HEADER) | $(OBJ_DIR)  
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(BONUS_DIR)/$(BONUS):		$(B_OBJS) $(B_HEADERS)
	$(CC) $(CFLAGS) $(B_INC) $(B_OBJS) $(LIBS) -o $@

$(BONUS_O_DIR)/%.o:			$(BONUS_DIR)/%.c $(BONUS_I_DIR)/$(HEADER) | $(BONUS_O_DIR)  
	$(CC) $(CFLAGS) $(B_INC) -c $< -o $@

$(BONUS_O_DIR):
		mkdir -p $(BONUS_O_DIR)

all:			$(SRC_DIR)/$(NAME)

bonus:			$(BONUS_DIR)/$(BONUS)

clean:                                   
		$(RM) -r $(OBJ_DIR)
		$(RM) -r $(BONUS_O_DIR)
	                                         
fclean:			clean 
		$(RM) $(SRC_DIR)/$(NAME)
		$(RM) $(BONUS_DIR)/$(BONUS)
	
re:				fclean all               

.PHONY:		all clean fclean re bonus 
