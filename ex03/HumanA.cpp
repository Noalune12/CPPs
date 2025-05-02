#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << GREEN << "Human A " << _name << " with initial weapon " << _weapon.getType() << " constructed" << RESET << std::endl;
}

HumanA::~HumanA() {
	std::cout << RED << "Human A " << _name << " with final weapon " << _weapon.getType() << " destructed" << RESET << std::endl;
}

void	HumanA::attack() const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
