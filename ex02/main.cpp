#include <iostream>
#include <string>

int	main(void) {
	int	nb = 42;
	int* nbptr = &nb;
	int& nbref = nb; // cannot change what the ref point to

	std::cout << nb << " " << *nbptr << " " << nbref << std::endl;

	*nbptr = 21;
	std::cout << nb << std::endl;
	nbref = 84;
	std::cout << nb << std::endl;
	return (0);
}
