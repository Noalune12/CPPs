/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:59:44 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:45 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap( void ): ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name): ClapTrap( name ) {
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const& src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(FragTrap const& name) {
	if (this != &name) {
		this->_name = name._name;
		this->_hitPoints = name._hitPoints;
		this->_energyPoints = name._energyPoints;
		this->_attackDamage = name._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints <= 0)
		std::cout << PURPLE << "FragTrap " << _name << " has not enough hit points to high fives!" << RESET << std::endl;
	else if (_energyPoints <= 0)
		std::cout << PURPLE << "FragTrap " << _name << " has not enough energy points high fives!" << RESET << std::endl;
	else {
		_energyPoints--;
		std::cout << PURPLE << "FragTrap " << _name << " HIGH FIVES 🖐️⚡️🖐️" << RESET << std::endl;
	}
}

void	FragTrap::attack( const std::string& target ) {
	if (_hitPoints <= 0)
		std::cout << RED << "FragTrap " << _name << " has not enough hit points to attack!" << RESET << std::endl;
	else if (_energyPoints <= 0)
		std::cout << RED << "FragTrap " << _name << " has not enough energy points to attack!"  << RESET << std::endl;
	else {
		_energyPoints--;
		std::cout << RED << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
	}
}
