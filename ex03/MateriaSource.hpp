#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "Storage.hpp"

class MateriaSource: public IMateriaSource {

	public:
		MateriaSource();
		MateriaSource(MateriaSource const& src);
		~MateriaSource();

		MateriaSource& operator=(MateriaSource const& src);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const& type);

	private:
		AMateria* _inventory[4];
		Storage _storage;
};

#endif
