#include "Character.hpp"
#include "color.h"

#include <iostream>
#include <algorithm>

Character::Character(): _name("Unknown") {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	// std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(std::string name): _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	// std::cout << "Character " << _name << " constructor called" << std::endl;
}

Character::Character(Character const& src): _name(src._name), _ground(src._ground) {
	for (int i = 0; i < 4; i++) {
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	// std::cout << BLUE << "Character copy constructor called" << RESET << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
			delete _inventory[i];
	}
	// std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(Character const& src) {
	if (this != &src) {
		_ground = src._ground;
		for (int i = 0; i < 4; i++)
			delete _inventory[i];
		_name = src._name;
		for (int i = 0; i < 4; i++) {
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	// std::cout << BLUE << "Character operator called" << RESET << std::endl;
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
		if (_inventory[i] != NULL && _inventory[i] == m) {
			std::cout << RED << "Character " << _name << " can't equip twice the same materia" << RESET << std::endl;
			return ;
		}
		if (_inventory[i] == NULL)
			j = i;
	}
	if (_inventory[j] == NULL) {
		_inventory[j] = m;
		_ground.compareStorage(_inventory[j]);
		std::cout << GREEN << "Character " << _name << " added item " << m->getType() << " at index " << j << RESET << std::endl;
	}
	else {
		_ground.compareStorage(m);
		_ground.addStorage(m);
		std::cout << RED << "Character " << _name << "'s inventory is full. " << m->getType() << " can't be added." << RESET << std::endl;
	}
}

void Character::unequip(int idx) {
	if (idx >= 4 || idx < 0 || _inventory[idx] == NULL) {
		std::cout << RED << "Character " << _name << " can't unequip" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "Character " << _name << " unequipped item " << _inventory[idx]->getType() << " at index " << idx << RESET << std::endl;
	_ground.addStorage(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 4 || idx < 0 || _inventory[idx] == NULL) {
		std::cout << RED << "Character " << _name << " can't use" << RESET << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

void Character::printGround() const {
	std::cout << _name << " storage : " << std::endl;
	_ground.printStorage();
	std::cout << "\ninventory : " << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			std::cout << _inventory[i]->getType() << " " << &_inventory[i] << std::endl;
		else
			std::cout << "NULL" << std::endl;
	}
}
