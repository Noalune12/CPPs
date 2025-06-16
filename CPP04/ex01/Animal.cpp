/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:21 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:22 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal( void ): type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const& src): type(src.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(Animal const& name) {
	if (this != &name) {
		type = name.type;
	}
	std::cout << "Animal operator called" << std::endl;
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "**Random animal sound**" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::setIdea(int index, std::string idea) {
	(void)index;
	(void)idea;
	std::cout << "I have no brain sorry" << std::endl;
}

std::string Animal::getIdea(int index) const {
	(void)index;
	return "I have no brain sorry";
}
