# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 16:08:59 by nraatika          #+#    #+#              #
#    Updated: 2026/01/07 16:38:03 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX          := c++
CXXFLAGS     := -Wall -Wextra -Werror -std=c++11 -g

NAME      := zoo

# Source files
SRCS  	:=	AAnimal.cpp  Cat.cpp  Dog.cpp main.cpp	Brain.cpp
# Object files
OBJS  := $(patsubst %.cpp,%.o,$(SRCS))

DEPS        =   $(OBJS:.o=.d)
DEPFLAGS    =   -MMD -MP

# Default target
all: 			$(NAME)

$(NAME):		$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Object file rules
$(OBJS):%.o:	%.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

# Clean target
clean:
	rm -rf $(OBJS) $(DEPS)

# Rebuild everything
fclean: 		clean
	rm -rf $(NAME)

# Recompile everything
re: 			fclean all
