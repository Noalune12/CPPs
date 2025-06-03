#include "Cat.hpp"

#include <iostream>

Cat::Cat() {
	std::cout << "Cat constuctor called" << std::endl;
	type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const& src): Animal(src) {
	std::cout << "Cat copy constuctor called" << std::endl;
}

Cat& Cat::operator=(Cat const& name) {
	if (this != &name) {
		Animal::operator=(name);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "**MEOW MEOW**" << std::endl;
}
