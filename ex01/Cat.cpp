/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:30 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:32 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "Cat operator called" << std::endl;
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
