#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
// # define CYAN "\033[36m"
# define RESET "\033[0m"

class MateriaSource: public IMateriaSource {

	public:
		MateriaSource();
		MateriaSource(MateriaSource const& src);
		~MateriaSource();

		MateriaSource& operator=(MateriaSource const& src);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const& type);

	private:
		AMateria* inventory[4];
};

#endif
