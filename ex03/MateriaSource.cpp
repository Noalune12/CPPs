#include "MateriaSource.hpp"
#include "color.h"

#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	std::cout << "Materia Source constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& src): _storage(src._storage) {
	for (int i = 0; i < 4; i++) {
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << BLUE << "Materia Source copy constructor called" << RESET << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
	std::cout << "Materia Source destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src) {
	if (this != &src) {
		for (int i = 0; i < 4; i++)
			delete _inventory[i];
		for (int i = 0; i < 4; i++) {
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		_storage = src._storage;
	}
	std::cout << BLUE << "Materia Source operator called" << RESET << std::endl;
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	int i;
	if (m == NULL) {
		std::cout << RED << "Null materia can't be learned" << RESET << std::endl;
		return ;
	}
	for (i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m->clone();
			std::cout << YELLOW << "Materia " << m->getType() << " learned" << RESET << std::endl;
			break;
		}
	}
	if (i == 4)
		std::cout << RED << "Materia Source's Invetory is full, a new materia can't be learned" << RESET << std::endl;
	// delete m; // add to a temp _inventory and delete at the end
	_storage.compareStorage(m);
	_storage.addStorage(m);
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type) {
			std::cout << PURPLE << "Materia " << type << " created" << RESET << std::endl;
			return _inventory[i]->clone();
		}
	}
	std::cout << RED << "Materia " << type << " can't be created" << RESET << std::endl;
	return NULL;
}

void MateriaSource::printContent() const {
	_storage.printStorage();
}
