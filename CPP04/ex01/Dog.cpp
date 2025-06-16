/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:35 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:36 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(): brain(new Brain()) {
	std::cout << "Dog constuctor called" << std::endl;
	type = "Dog";
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const& src): Animal(src) {
	brain = new Brain(*src.brain);
	std::cout << "Dog copy constuctor called" << std::endl;
}

Dog& Dog::operator=(Dog const& name) {
	if (this != &name) {
		Animal::operator=(name);
		delete brain;
		brain = new Brain(*name.brain);
	}
	std::cout << "Dog operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "**WOOF WOOF**" << std::endl;
}

void Dog::setIdea(int index, std::string idea) {
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
	return brain->getIdea(index);
}
