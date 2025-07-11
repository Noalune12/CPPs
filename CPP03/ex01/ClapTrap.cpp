/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:59:04 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:05 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap( void ): _name("ClapTrap with no name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap ( ClapTrap const& src ) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( ClapTrap const& name ) {
	if (this != &name) {
		this->_name = name._name;
		this->_hitPoints = name._hitPoints;
		this->_energyPoints = name._energyPoints;
		this->_attackDamage = name._attackDamage;
	}
	return *this;
}

void ClapTrap::attack( const std::string& target ) {
	if (_hitPoints <= 0)
		std::cout << RED << "ClapTrap " << _name << " has not enough hit points to attack!" << RESET << std::endl;
	else if (_energyPoints <= 0)
		std::cout << RED << "ClapTrap " << _name << " has not enough energy points to attack!"  << RESET << std::endl;
	else {
		_energyPoints--;
		std::cout << RED << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
		std::cout << BLUE << "ClapTrap " << _name << " has not enough hit points to repair itself!" << RESET << std::endl;
	else if (_energyPoints <= 0)
		std::cout << BLUE << "ClapTrap " << _name << " has not enough energy points to repair itself!" << RESET << std::endl;
	else if (_hitPoints > 4294967295 - amount)
		std::cout << BLUE << "ClapTrap " << _name << " can't have more than 4294967295 hit points" << RESET << std::endl;
	else {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << BLUE << "ClapTrap " << _name << " repairs itself and gains " << amount << " points of hit points!" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0)
		std::cout << YELLOW << "ClapTrap " << _name << " can't take more damage!" << RESET << std::endl;
	else if (_hitPoints <= amount) {
		_hitPoints = 0;
		std::cout << YELLOW << "ClapTrap " << _name << " loses all its hit points!" << RESET << std::endl;
	}
	else {
		_hitPoints -= amount;
		std::cout << YELLOW << "ClapTrap " << _name << " takes " << amount << " points of damage!" << RESET << std::endl;
	}
}

void ClapTrap::printStatus( void ) const {
	std::cout << GREEN << "ClapTrap " << _name << " has " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage!" << RESET << std::endl;
}

