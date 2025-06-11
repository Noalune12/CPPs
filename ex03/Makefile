CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3
NAME = Materia
SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp Storage.cpp
OBJDIR = objs
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp Storage.hpp Makefile
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
