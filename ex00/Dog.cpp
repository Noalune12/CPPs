/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:00 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:01 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
