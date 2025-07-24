# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 13:51:50 by nraatika          #+#    #+#              #
#    Updated: 2025/07/23 13:39:16 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minitalk
CLIENT		:= client
SERVER		:= server

SRC_DIR		:= srcs
OBJ_DIR		:= objs
BONUS_DIR	:= bonus_objs
INC_DIR		:= include

SRCS_C		:=	client.c
SRCS_S		:=	server.c
HEADER		:=	minitalk.h

OBJS_C		:= $(addprefix $(OBJ_DIR)/, $(SRCS_C:.c=.o))
OBJS_S		:= $(addprefix $(OBJ_DIR)/, $(SRCS_S:.c=.o))

CLIENT_B		:= $(BONUS_DIR)/client
SERVER_B		:= $(BONUS_DIR)/server

SRCS_C_BONUS	:=	client_bonus.c
SRCS_S_BONUS	:=	server_bonus.c

OBJS_C_BONUS	:= $(addprefix $(BONUS_DIR)/, $(SRCS_C_BONUS:.c=.o))
OBJS_S_BONUS	:= $(addprefix $(BONUS_DIR)/, $(SRCS_S_BONUS:.c=.o))

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
BUFFER_SIZE	:= 1000000
ifeq	($(origin buffer), undefined)
	BUFFER_SIZE_VALUE = $(BUFFER_SIZE)
else
	BUFFER_SIZE_VALUE = $(buffer)
endif
BUFFER_ID	:= .buffer_$(BUFFER_SIZE_VALUE)
CFLAGS		+= -DBUFFER_SIZE=$(BUFFER_SIZE_VALUE)

RM			:= rm -f

LIBFT_DIR	:= ./libft
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBFT_H		:= $(LIBFT_DIR)/libft.h

INC			:= -I./$(INC_DIR)
LIBS		:= -L$(LIBFT_DIR) -lft


$(NAME):		$(CLIENT) $(SERVER) $(LIBFT)

$(CLIENT):		$(OBJS_C) $(INC_DIR)/$(HEADER) $(LIBFT) $(SLEEP_ID)
		$(CC) $(CFLAGS) $(INC) $(OBJS_C) $(LIBS) -o $(CLIENT)

$(SERVER):		$(OBJS_S) $(INC_DIR)/$(HEADER) $(LIBFT) $(SLEEP_ID)
		$(CC) $(CFLAGS) $(INC) $(OBJS_S) $(LIBS) -o $(SERVER)


$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INC_DIR)/$(HEADER) $(LIBFT) | $(OBJ_DIR)  
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):		
		$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(CLIENT_B):		$(OBJS_C_BONUS) $(INC_DIR)/$(HEADER) $(LIBFT)
		$(CC) $(CFLAGS) $(INC) $(OBJS_C_BONUS) $(LIBS) -o $(CLIENT_B)

$(SERVER_B):		$(OBJS_S_BONUS) $(INC_DIR)/$(HEADER) $(LIBFT)
		$(CC) $(CFLAGS) $(INC) $(OBJS_S_BONUS) $(LIBS) -o $(SERVER_B)


$(BONUS_DIR)/%.o:	$(SRC_DIR)/%.c $(INC_DIR)/$(HEADER) $(LIBFT) | $(BONUS_DIR)  
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BONUS_DIR):
		mkdir -p $(BONUS_DIR)

$(BUFFER_ID):
		@rm -f .buffer_*
		@echo $(BUFFER_SIZE_VALUE) > $@

all:			$(NAME)

bonus:			$(CLIENT_B) $(SERVER_B) $(LIBFT)

clean:                                   
		$(RM) -r $(OBJ_DIR)
		$(RM) -r $(BONUS_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean
                                         
fclean:			clean 
		$(RM) $(CLIENT) $(SERVER) $(BONUS) $(BUFFER_ID)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:				fclean all               

.PHONY:		all clean fclean re $(NAME) bonus
