# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 15:17:23 by lbuisson          #+#    #+#              #
#    Updated: 2025/03/31 15:17:25 by lbuisson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = phonebook
SRC = main.cpp Contact.cpp PhoneBook.cpp print.cpp
OBJDIR = objs
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp PhoneBook.hpp Contact.hpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
