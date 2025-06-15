#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"

int main() {
	try {
		Bureaucrat charlie("Charlie", 145);
		Bureaucrat erwan("Erwan", 137);
		ShrubberyCreationForm form1("home");
		erwan.executeForm(form1);
		// std::cout << form1 << std::endl;
		charlie.signForm(form1);
		// std::cout << form1 << std::endl;
		charlie.executeForm(form1);
		erwan.executeForm(form1);
		// std::cout << form1 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
