CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = phonebook
SRC = main.cpp
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
