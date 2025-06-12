#include "Weapon.hpp"

#include <iostream>

Weapon::Weapon() {
	std::cout << "✨ Weapon Constructor called ✨" << std::endl;
}

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << _type << " Constructor called ✨" << std::endl;
}

Weapon::~Weapon() {
	std::cout << _type << " Destructor called ✨" << std::endl;
}

const std::string&	Weapon::getType() const {
	return (_type);
}

void	Weapon::setType(const std::string& newType) {
	_type = newType;
}
