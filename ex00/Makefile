# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 16:08:59 by nraatika          #+#    #+#              #
#    Updated: 2026/01/08 16:33:28 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX          := c++
CXXFLAGS     := -Wall -Wextra -Werror -std=c++11 -g

NAME      := fixed

SRCS  	:=	main.cpp Fixed.cpp

OBJS  := $(patsubst %.cpp,%.o,$(SRCS))

DEPS        =   $(OBJS:.o=.d)
DEPFLAGS    =   -MMD -MP

all: 			$(NAME)

$(NAME):		$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS):%.o:	%.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: 		clean
	rm -rf $(NAME)

re: 			fclean all

PHONY: all clean fclean re
