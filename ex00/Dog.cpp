#include "Dog.hpp"

#include <iostream>

Dog::Dog() {
	std::cout << "Dog constuctor called" << std::endl;
	type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const& src): Animal(src) {
	std::cout << "Dog copy constuctor called" << std::endl;
}

Dog& Dog::operator=(Dog const& name) {
	if (this != &name) {
		Animal::operator=(name);
	}
	std::cout << "Dog operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "**WOOF WOOF**" << std::endl;
}

std::string Dog::getType() const {
	return type;
}
