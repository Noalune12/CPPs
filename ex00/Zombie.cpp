#include "Zombie.hpp"

Zombie::Zombie() {
	_name = "Unknown";
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::Zombie(std::string name) {
	_name = name;
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie : " << _name << " destructor called" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
