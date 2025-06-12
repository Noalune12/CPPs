#include "Zombie.hpp"

int	main(void) {
	int n = 10;
	Zombie z1("Zombie 1");
	Zombie z2("Zombie 2");
	Zombie* z3 = zombieHorde(n, "zombiesssss");

	z1.announce();
	z2.announce();
	for (int i = 0; i < n; i++)
		z3[i].announce();
	delete [] z3;
	return (0);
}
