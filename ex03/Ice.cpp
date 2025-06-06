#include "Ice.hpp"

#include <iostream>

Ice::Ice() {
	_type = "ice";
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const& src): AMateria(src) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(Ice const& name) {
	if (this != &name) {
		AMateria::operator=(name);
	}
	std::cout << "Ice operator called" << std::endl;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << PURPLE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
