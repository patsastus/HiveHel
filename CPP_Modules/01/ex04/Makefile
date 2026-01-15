# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 16:08:59 by nraatika          #+#    #+#              #
#    Updated: 2026/01/02 12:49:20 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX          := c++
CXXFLAGS     := -Wall -Wextra -Werror -std=c++17 -g

NAME      := replace

# Source files
SRCS  	:= main.cpp Replacer.cpp
TSTS	:= tester.cpp

# Object files
OBJS  		:= $(patsubst %.cpp,%.o,$(SRCS))

DEPS        =   $(OBJS:.o=.d)
DEPFLAGS    =   -MMD -MP

# Default target
all: 			$(NAME)

$(NAME):		$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

tester:			 $(NAME)
	$(CXX) $(CXXFLAGS) $(TSTS) -o tester
	./tester
	chmod +x run_tests.sh
	./run_tests.sh

$(OBJS):%.o:	%.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: 		clean
	rm -rf $(NAME) tester run_tests.sh test.txt

re: 			fclean all

PHONY: all clean fclean re
