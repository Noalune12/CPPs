#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria(): _type("unknown") {
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type): _type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const& src): _type(src._type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(AMateria const& name) {
	if (this != &name) {
		_type = name._type;
	}
	std::cout << "AMateria operator called" << std::endl;
	return *this;
}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "*use an unknown materia on " << target.getName() << " *" << std::endl;
}
