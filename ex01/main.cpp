#include "Zombie.hpp"

int	main(void) {
	Zombie z1("Zombie 1");
	Zombie z2("Zombie 2");
	Zombie* z3 = zombieHorde(10, "zombiesssss");

	z1.announce();
	z2.announce();
	for (int i = 0; i < 10; i++)
		z3[i].announce();
	delete [] z3;
	return (0);
}
