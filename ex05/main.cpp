#include "Harl.hpp"

#include <iostream>


int main(int ac, char **av) {
	Harl	harl;

	if (ac != 2) {
		std::cout << "Invalid number of arguments. (DEBUG, INFO, WARNING or ERROR)" << std::endl;
		return (1);
	}
	harl.complain(std::string(av[1]));
	return (0);
}
