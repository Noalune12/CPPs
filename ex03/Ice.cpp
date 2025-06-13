/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:33:17 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:33:18 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include "color.h"

#include <iostream>

Ice::Ice() {
	_type = "ice";
	// std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const& src): AMateria(src) {
	// std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
	// std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(Ice const& name) {
	if (this != &name) {
		AMateria::operator=(name);
	}
	// std::cout << "Ice operator called" << std::endl;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << PURPLE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
