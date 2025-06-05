#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() {
	std::cout << "Wrong Cat constuctor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "Wrong Cat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& src): WrongAnimal(src) {
	std::cout << "WrongCat copy constuctor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const& name) {
	if (this != &name) {
		WrongCat::operator=(name);
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "**MEOW MEOW**" << std::endl;
}
