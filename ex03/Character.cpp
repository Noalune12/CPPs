#include "Character.hpp"

#include <iostream>
#include <algorithm>

Character::Character(): _name("Unknown"), groundCapacity(10), groundSize(0) {
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
	ground = new AMateria*[groundCapacity];
	std::cout << "Default Character constructor called" << std::endl;
}

Character::Character(std::string name): _name(name), groundCapacity(10), groundSize(0) {
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
	ground = new AMateria*[groundCapacity];
	std::cout << "Character " << _name << " constructor called" << std::endl;
}

Character::Character(Character const& src): _name(src._name), groundCapacity(src.groundCapacity), groundSize(src.groundSize) {
	for (int i = 0; i < 4; i++) {
		if (src.inventory[i])
			inventory[i] = src.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	ground = new AMateria*[groundCapacity];
	for (int i = 0; i < groundSize; i++)
	{
		if (src.ground[i])
			ground[i] = src.ground[i]->clone();
		else
			ground[i] = NULL;
	}
	std::cout << BLUE << "Character copy constructor called" << RESET << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
			delete inventory[i];
	}
	for (int i = 0; i < groundSize; i++) {
		delete ground[i];
	}
	delete[] ground;
	std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(Character const& src) {
	if (this != &src) {
		for (int i = 0; i < 4; i++)
			delete inventory[i];
		for (int i = 0; i < groundSize; i++) {
			delete ground[i];
		}
		delete[] ground;
		_name = src._name;
		groundCapacity = src.groundCapacity;
		groundSize = src.groundSize;
		for (int i = 0; i < 4; i++) {
			if (src.inventory[i])
				inventory[i] = src.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		ground = new AMateria*[groundCapacity];
		for (int i = 0; i < groundSize; i++) {
			if (src.ground[i])
				ground[i] = src.ground[i]->clone();
			else
				ground[i] = NULL;
		}
	}
	std::cout << BLUE << "Character operator called" << RESET << std::endl;
	return *this;
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
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
		for (int i = 0; i < groundSize; i++) {
			if (ground[i] && ground[i] == inventory[j]) {
				ground[i] = NULL;
				break;
			}
		}
		std::cout << GREEN << "Character " << _name << " added item at index " << j << RESET << std::endl;
	}
	else {
		std::cout << RED << "Character " << _name << "'s inventory is full" << RESET << std::endl;
		delete m;
		m = NULL;
	}
}

void Character::unequip(int idx) {
	if (idx >= 4 || idx < 0 || inventory[idx] == NULL) {
		std::cout << RED << "Character " << _name << " can't unequip" << RESET << std::endl;
		return ;
	}
	if (groundSize == groundCapacity) {
		groundCapacity *= 2;
		AMateria** newGround = new AMateria*[groundCapacity];
		for (int i = 0; i < groundSize; i++)
			newGround[i] = ground[i];
		delete[] ground;
		ground = newGround;
	}
	ground[groundSize++] = inventory[idx];
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
