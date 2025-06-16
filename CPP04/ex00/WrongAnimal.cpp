/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:11 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:12 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal( void ): type("WrongAnimal") {
	std::cout << "Wrong Animal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "Wrong Animal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src): type(src.type) {
	std::cout << "Wrong Animal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& name) {
	if (this != &name) {
		type = name.type;
	}
	std::cout << "Wrong Animal operator called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "**Random Wrong Animal sound**" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
