#include "Cure.hpp"

#include <iostream>

Cure::Cure() {
	_type = "cure";
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const& src): AMateria(src) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(Cure const& name) {
	if (this != &name) {
		AMateria::operator=(name);
	}
	std::cout << "Cure operator called" << std::endl;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);

}

void Cure::use(ICharacter& target) {
	std::cout << PURPLE << "* heals " << target.getName() << " ’s wounds *" << RESET << std::endl;
}
