#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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
		RobotomyRequestForm form2("random");
		erwan.executeForm(form2);
		erwan.signForm(form2);
		for (int i = erwan.getGrade(); i > form2.getSignGrade(); i--)
			erwan.incrementGrade();
		std::cout << erwan << std::endl;
		erwan.signForm(form2);
		for (int i = charlie.getGrade(); i > form2.getExecuteGrade(); i--)
			charlie.incrementGrade();
		std::cout << charlie << std::endl;
		charlie.executeForm(form2);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
