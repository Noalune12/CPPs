#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
	std::cout << "Materia Source constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& src) {
	for (int i = 0; i < 4; i++) {
		if (src.inventory[i])
			inventory[i] = src.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	std::cout << BLUE << "Materia Source copy constructor called" << RESET << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete inventory[i];
	}
	std::cout << "Materia Source destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src) {
	if (this != &src) {
		for (int i = 0; i < 4; i++)
			delete inventory[i];
		for (int i = 0; i < 4; i++) {
			if (src.inventory[i])
				inventory[i] = src.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	std::cout << BLUE << "Materia Source operator called" << RESET << std::endl;
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL) {
		std::cout << RED << "Null materia can't be learned" << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			std::cout << YELLOW << "Materia " << m->getType() << " learned" << RESET << std::endl;
			return;
		}
	}
	std::cout << RED << "Materia Source's Invetory is full, a new materia can't be learned" << RESET << std::endl;
	delete m; // add to a temp inventory and delete at the end
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] && inventory[i]->getType() == type) {
			std::cout << PURPLE << "Materia " << type << " created" << RESET << std::endl;
			return inventory[i]->clone();
		}
	}
	std::cout << RED << "Materia " << type << " can't be created" << RESET << std::endl;
	return NULL;
}
