/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:30:55 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:30:56 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
