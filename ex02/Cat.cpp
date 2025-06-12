#include "Cat.hpp"

#include <iostream>

Cat::Cat(): brain(new Brain()) {
	std::cout << "Cat constuctor called" << std::endl;
	type = "Cat";
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const& src): Animal(src) {
	brain = new Brain(*src.brain);
	std::cout << "Cat copy constuctor called" << std::endl;
}

Cat& Cat::operator=(Cat const& name) {
	if (this != &name) {
		Animal::operator=(name);
		delete brain;
		brain = new Brain(*name.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "**MEOW MEOW**" << std::endl;
}

void Cat::setIdea(int index, std::string idea)  {
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
	return brain->getIdea(index);
}
