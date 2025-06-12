#include "Zombie.hpp"

int	main(void) {
	Zombie z1("Zombie 1");
	Zombie z2("Zombie 2");
	Zombie* z3 = newZombie("Zombie 3");

	z1.announce();
	z2.announce();
	z3->announce();
	randomChump("NEW ZOMBIE");
	z3->announce();
	randomChump("NEW NEW ZOMBIE");
	z3->announce();
	delete z3;
	return (0);
}
