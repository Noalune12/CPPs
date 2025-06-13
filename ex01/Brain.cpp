/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:26 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:27 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>
#include <sstream>

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << "Idea number " << i;
		ideas[i] = ss.str();
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const& src) {
	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(Brain const& name) {
	if (this != &name) {
		for (int i = 0; i < 100; i++)
			ideas[i] = name.ideas[i];
	}
	std::cout << "Brain operator called" << std::endl;
	return (*this);
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100)
		return ("Incorrect Index");
	return (ideas[index]);
}

void Brain::setIdea(int index, std::string add) {
	if (index < 0 || index >= 100)
		return;
	ideas[index] = add;
}
