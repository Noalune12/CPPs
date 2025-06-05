#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

int main() {
	{
		std::cout << RED << "MATERIA TEST:\n" << RESET << std::endl;

		std::cout << BLUE << "Default constructor:" << RESET << std::endl;
		Ice ice1;
		std::cout << "Type: " << ice1.getType() << std::endl;
		Cure cure1;
		std::cout << "Type: " << cure1.getType() << std::endl;

		std::cout << BLUE << "\nParameterized constructor:" << RESET << std::endl;
		AMateria* ice2 = ice1.clone();
		std::cout << "Cloned Type: " << ice2->getType() << std::endl;
		AMateria* cure2 = cure1.clone();
		std::cout << "Cloned Type: " << cure2->getType() << std::endl;

		std::cout << BLUE << "\nCopy constructor:" << RESET << std::endl;
		Ice ice3(ice1);
		std::cout << "Type: " << ice3.getType() << std::endl;
		Cure cure3(cure1);
		std::cout << "Type: " << cure3.getType() << std::endl;

		std::cout << BLUE << "\nAssignment operator:" << RESET << std::endl;
		Ice ice4;
		ice4 = ice1;
		std::cout << "Type: " << ice4.getType() << std::endl;
		Cure cure4;
		cure4 = cure1;
		std::cout << "Type: " << cure4.getType() << std::endl;

		std::cout << BLUE << "\nTesting destructor:" << RESET << std::endl;
		delete ice2;
		delete cure2;
	}

	return 0;}
