#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

#define TOO_LOW
#define TOO_HIGH
#define OVERFLOW_UP
#define OVERFLOW_DOWN

# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"

int main() {
	// Wrong grade
	std::cout << YELLOW << "Wrong grade\n" << RESET << std::endl;
	#ifdef TOO_LOW
		try {
			Bureaucrat charlie("Charlie", -9);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	#endif
	#ifdef TOO_HIGH
	std::cout << std::endl;
		try {
			Bureaucrat charlie("Charlie", 180);
		} catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	#endif

	// Overflows
	std::cout << YELLOW << "\nOverflow\n" << RESET << std::endl;
	#ifdef OVERFLOW_UP
	try {
		Bureaucrat charlie("Charlie", 2);
		std::cout << charlie << std::endl;
		charlie.incrementGrade();
		std::cout << charlie << std::endl;
		charlie.incrementGrade();
		std::cout << charlie << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	#endif
	#ifdef OVERFLOW_DOWN
	std::cout << std::endl;
	try {
		Bureaucrat charlie("Charlie", 149);
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	#endif

	std::cout << YELLOW << "\nCorrect\n" << RESET << std::endl;
	try {
		Bureaucrat charlie("Charlie", 2);
		std::cout << charlie << std::endl;
		std::cout << BLUE << "Decrement of 10" << RESET << std::endl;
		for (int i = 0; i < 10; i++)
			charlie.decrementGrade();
		std::cout << charlie << std::endl;
		std::cout << BLUE << "Increment of 5" << RESET << std::endl;
		for (int i = 0; i < 5; i++)
			charlie.incrementGrade();
		std::cout << charlie << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
