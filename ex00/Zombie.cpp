#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::Zombie(std::string name) {
	_name = name;
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie destructor called" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

// Zombie* newZombie(std::string name) {
// 	new Zombie(name);
// 	return Zombie;
// }
