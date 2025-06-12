#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	std::cout << GREEN << "Human B " << _name << " with no initial weapon constructed" << RESET << std::endl;
};

HumanB::~HumanB() {
	if (_weapon == NULL)
		std::cout << RED << "Human B " << _name << " with no final weapon destructed" << RESET << std::endl;
	else
		std::cout << RED<< "Human B " << _name << " with final weapon \"" << _weapon->getType() << "\" destructed" << RESET << std::endl;
	};

void	HumanB::attack() const {
	if (_weapon == NULL)
		std::cout << _name << " has no weapon and can't attack. ❌" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
