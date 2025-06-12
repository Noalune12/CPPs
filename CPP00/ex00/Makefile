# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 15:18:03 by lbuisson          #+#    #+#              #
#    Updated: 2025/03/31 15:18:05 by lbuisson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = megaphone
SRC = megaphone.cpp
OBJDIR = objs
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
