#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

int main() {
	try {
		std::cout << YELLOW << "INVALID FORM\n" << RESET << std::endl;
		Intern someRandomIntern;
		AForm* form;
		form = someRandomIntern.makeForm("another form", "sorry");
		delete form;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* form;
		Bureaucrat charlie("Charlie", 145);
		Bureaucrat erwan("Erwan", 137);
		std::cout << YELLOW << "\nSHRUBBERY CREATION FORM\n" << RESET << std::endl;
		form = someRandomIntern.makeForm("shrubbery creation", "home");
		std::cout << *form << "\n" << std::endl;
		std::cout << erwan << "\n" << std::endl;
		erwan.executeForm(*form);
		std::cout << "\n" << charlie << "\n" << std::endl;
		charlie.signForm(*form);
		charlie.executeForm(*form);
		erwan.executeForm(*form);
		delete form;

		std::cout << YELLOW << "\nROBOTOMY REQUEST FORM\n" << RESET << std::endl;
		form = someRandomIntern.makeForm("robotomy request", "random");
		std::cout << *form << "\n" << std::endl;
		erwan.executeForm(*form);
		erwan.signForm(*form);
		for (int i = erwan.getGrade(); i > form->getSignGrade(); i--)
			erwan.incrementGrade();
		std::cout << "\n" << erwan << "\n" << std::endl;
		erwan.signForm(*form);
		for (int i = charlie.getGrade(); i > form->getExecuteGrade(); i--)
			charlie.incrementGrade();
		std::cout << "\n" << charlie << "\n" << std::endl;
		charlie.executeForm(*form);
		delete form;

		std::cout << YELLOW << "\nPRESIDENTIAL PARDON FORM\n" << RESET << std::endl;
		form = someRandomIntern.makeForm("presidential pardon", "sorry");
		std::cout << *form << "\n" << std::endl;
		charlie.executeForm(*form);
		charlie.signForm(*form);
		for (int i = charlie.getGrade(); i > form->getSignGrade(); i--)
			charlie.incrementGrade();
		std::cout << "\n" << charlie << "\n" << std::endl;
		charlie.signForm(*form);
		for (int i = erwan.getGrade(); i > form->getExecuteGrade(); i--)
			erwan.incrementGrade();
		std::cout << "\n" << erwan << "\n" << std::endl;
		erwan.executeForm(*form);
		delete form;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
