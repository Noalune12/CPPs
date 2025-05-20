#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap( void ): _name("ClapTrap with no name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap ( ClapTrap const& src ) {
	*this = src;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( ClapTrap const& name ) {
	this->_name = name.getName();
	this->_hitPoints = name.getHitPoints();
	this->_energyPoints = name.getEnergyPoints();
	this->_attackDamage = name.getAttackDamage();
	return *this;
}

unsigned int ClapTrap::getHitPoints( void ) const {
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints( void ) const {
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage( void ) const {
	return _attackDamage;
}

std::string ClapTrap::getName( void ) const {
	return _name;
}

void ClapTrap::attack( const std::string& target ) {
	if (_hitPoints <= 0)
		std::cout << RED << "ClapTrap " << _name << " has not enough hit points to attack!" << RESET << std::endl;
	else if (_energyPoints <= 0)
		std::cout << RED << "ClapTrap " << _name << " has not enough energy points to attack!"  << RESET<< std::endl;
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

