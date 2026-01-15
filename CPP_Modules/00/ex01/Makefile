# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 16:08:59 by nraatika          #+#    #+#              #
#    Updated: 2025/10/17 12:18:35 by nraatika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX          := c++
CXXFLAGS     := -Wall -Wextra -Werror -std=c++11 -g

TARGET      := phonebook

# Source files
SRCS  	:=	PhoneBook.cpp Contact.cpp main.cpp 

# Object files
OBJS  := $(patsubst %.cpp,%.o,$(SRCS))

# Default target
all: 			$(TARGET)

$(TARGET):		$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Object file rules
$(OBJS):%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJS)

# Rebuild everything
fclean: 		clean
	rm -rf $(TARGET)

# Recompile everything
re: 			fclean all
