#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap( void ): ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src): ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& name) {
	if (this != &name) {
		ClapTrap::operator=(name);
	}
	return *this;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << CYAN << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << RESET << std::endl;
}

void	DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}
