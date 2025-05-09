# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 09:54:33 by nraatika          #+#    #+#              #
#    Updated: 2025/05/09 10:11:29 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=ft_printf.c	ft_convert.c	make_flags.c	write_char.c\
		write_str.c		write_ptr.c		write_int.c		write_uint.c\
		write_hex.c		ft_utoa.c		ft_itoa_hex.c

B_DIR	=bonus/
B_SRCS	=make_flags_bonus.c	ft_convert_bonus.c	ft_printf_bonus.c\
		write_char_bonus.c	write_str_bonus.c	write_ptr_bonus.c\
		write_int_bonus.c	write_uint_bonus.c	write_hex_bonus.c\
		padding_bonus.c

OBJS	=$(SRCS:%.c=%.o)
B_OBJS	=$(B_SRCS:%.c=$(B_DIR)%.o)

NAME    =libftprintf.a 
HEADER  =libftprintf.h 
B_HEAD	=$(B_DIR)libftprintf_bonus.h
LIBFT	=libft/libft.a
LIBFT_H	=libft/libft.h

CC      =cc 
CFLAGS  =-Wall -Wextra -Werror
RM      =rm -f
BONUS	=.bonus

all:			$(NAME)

$(NAME):		$(OBJS)	$(LIBFT)
				cp $(LIBFT) $(NAME)
				ar rcs $(NAME) $(OBJS)

$(OBJS:%.o):	$(SRCS:%.c) $(HEADER) $(LIBFT_H)
				$(CC) $(CFLAGS) $(HEADER) $(LIBFT_H) -c $< -o $@

$(B_OBJS:%.o):	$(B_DIR)$(B_SRCS:%.c) $(B_HEAD) $(LIBFT_H)
				$(CC) $(CFLAGS) $(B_HEAD) $(LIBFT_H) -c $< -o $@

$(LIBFT):
				$(MAKE) -C libft

clean:
				@$(RM) $(OBJS) $(B_OBJS)
				@$(MAKE) -C libft clean

fclean:			clean 
				@$(RM) $(NAME) $(BONUS)
				@$(MAKE) -C libft fclean

re:				fclean all 

bonus:			$(BONUS)

$(BONUS):		$(NAME) $(LIBFT) $(B_OBJS)
				ar d $(NAME) ft_printf.o
				ar rcs $(NAME) $(B_OBJS)
				touch $(BONUS)

.PHONY:         all clean fclean re bonus
