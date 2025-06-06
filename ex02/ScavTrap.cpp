/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:59:31 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:32 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap( void ): ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name): ClapTrap( name ) {
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const& src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& name) {
	if (this != &name) {
		this->_name = name._name;
		this->_hitPoints = name._hitPoints;
		this->_energyPoints = name._energyPoints;
		this->_attackDamage = name._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::guardGate( void ) {
	if (_hitPoints <= 0)
		std::cout << PURPLE << "ScavTrap " << _name << " has not enough hit points to gate keep!" << RESET << std::endl;
	else if (_energyPoints <= 0)
		std::cout << PURPLE << "ScavTrap " << _name << " has not enough energy points to gate keep!" << RESET << std::endl;
	else {
		_energyPoints--;
		std::cout << PURPLE << "ScavTrap " << _name << " is in Gate Keeper mode" << RESET << std::endl;
	}
}

void	ScavTrap::attack( const std::string& target ) {
	if (_hitPoints <= 0)
		std::cout << RED << "ScavTrap " << _name << " has not enough hit points to attack!" << RESET << std::endl;
	else if (_energyPoints <= 0)
		std::cout << RED << "ScavTrap " << _name << " has not enough energy points to attack!"  << RESET << std::endl;
	else {
		_energyPoints--;
		std::cout << RED << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
	}
}
