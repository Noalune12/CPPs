#include "Character.hpp"

#include <iostream>
#include <algorithm>

Character::Character(): _name("Unknown") {
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
	std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(std::string name): _name(name) {
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
	std::cout << "Character " << _name << " constructor called" << std::endl;
}

