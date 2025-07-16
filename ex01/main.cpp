#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"

int main() {
	// Wrong grade
	std::cout << YELLOW << "Wrong grade\n" << RESET << std::endl;
		try {
			Bureaucrat charlie("Charlie", -9);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	std::cout << std::endl;
		try {
			Bureaucrat charlie("Charlie", 180);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	std::cout << std::endl;
		try {
			Form alpha("alpha", 0, 1);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	std::cout << std::endl;
		try {
			Form alpha("alpha", 1, 0);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	std::cout << std::endl;
		try {
			Form alpha("alpha", 2000, 1);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	std::cout << std::endl;
		try {
			Form alpha("alpha", 1, 2000);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	// Can't sign
	std::cout << YELLOW << "\nCan't sign\n" << RESET << std::endl;
	try {
		Bureaucrat charlie("Charlie", 2);
		Form alpha("alpha", 1, 1);
		std::cout << charlie << std::endl;
		std::cout << alpha << std::endl;
		charlie.signForm(alpha);
		std::cout << charlie << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << YELLOW << "\nCorrect\n" << RESET << std::endl;
	try {
		Bureaucrat charlie("Charlie", 2);
		Form alpha("alpha", 1, 1);
		std::cout << charlie << std::endl;
		std::cout << alpha << std::endl;
		std::cout << BLUE << "Decrement of 10" << RESET << std::endl;
		for (int i = 0; i < 10; i++)
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
		std::cout << BLUE << "Increment of 11" << RESET << std::endl;
		for (int i = 0; i < 11; i++)
		charlie.incrementGrade();
		std::cout << charlie << std::endl;
		charlie.signForm(alpha);
		std::cout << alpha << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
