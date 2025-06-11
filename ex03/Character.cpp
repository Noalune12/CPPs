#include "Character.hpp"
#include "Storage.hpp"

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

Character::Character(Character const& src): _name(src._name), _ground(src._ground) {
	for (int i = 0; i < 4; i++) {
		if (src.inventory[i])
			inventory[i] = src.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	std::cout << BLUE << "Character copy constructor called" << RESET << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
			delete inventory[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(Character const& src) {
	if (this != &src) {
		for (int i = 0; i < 4; i++)
			delete inventory[i];
		_name = src._name;
		for (int i = 0; i < 4; i++) {
			if (src.inventory[i])
				inventory[i] = src.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		_ground = src._ground;
	}
	std::cout << BLUE << "Character operator called" << RESET << std::endl;
	return *this;
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
		std::cout << RED << "Null materia can't be equiped" << RESET << std::endl;
		return ;
	}
	int j = 0;
	for (int i = 3; i >= 0; i--) {
		if (inventory[i] != NULL && inventory[i] == m) {
			std::cout << RED << "Character " << _name << " can't equip twice the same materia" << RESET << std::endl;
			return ;
		}
		if (inventory[i] == NULL)
			j = i;
	}
	if (inventory[j] == NULL) {
		inventory[j] = m;
		_ground.compareStorage(inventory[j]);
		std::cout << GREEN << "Character " << _name << " added item at index " << j << RESET << std::endl;
	}
	else {
		_ground.compareStorage(m);
		_ground.addStorage(m);
		std::cout << RED << "Character " << _name << "'s inventory is full" << RESET << std::endl;
	}
}

void Character::unequip(int idx) {
	if (idx >= 4 || idx < 0 || inventory[idx] == NULL) {
		std::cout << RED << "Character " << _name << " can't unequip" << RESET << std::endl;
		return ;
	}
	_ground.addStorage(inventory[idx]);
	inventory[idx] = NULL;
	std::cout << GREEN << "Character " << _name << " unequipped item at index " << idx << RESET << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 4 || idx < 0 || inventory[idx] == NULL) {
		std::cout << RED << "Character " << _name << " can't use" << RESET << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}

void Character::printGround() const {
	std::cout << _name << " storage : " << std::endl;
	_ground.printStorage();
}
