#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

int main() {
	try {
		Bureaucrat charlie("Charlie", 145);
		Bureaucrat erwan("Erwan", 137);
		std::cout << YELLOW << "SHRUBBERY CREATION FORM\n" << RESET << std::endl;
		ShrubberyCreationForm form1("home");
		std::cout << form1 << "\n" << std::endl;
		std::cout << erwan << "\n" << std::endl;
		erwan.executeForm(form1);
		std::cout << "\n" << charlie << "\n" << std::endl;
		charlie.signForm(form1);
		charlie.executeForm(form1);
		erwan.executeForm(form1);

		std::cout << YELLOW << "\nROBOTOMY REQUEST FORM\n" << RESET << std::endl;
		RobotomyRequestForm form2("random");
		std::cout << form2 << "\n" << std::endl;
		erwan.executeForm(form2);
		erwan.signForm(form2);
		for (int i = erwan.getGrade(); i > form2.getSignGrade(); i--)
			erwan.incrementGrade();
		std::cout << "\n" << erwan << "\n" << std::endl;
		erwan.signForm(form2);
		for (int i = charlie.getGrade(); i > form2.getExecuteGrade(); i--)
			charlie.incrementGrade();
		std::cout << "\n" << charlie << "\n" << std::endl;
		charlie.executeForm(form2);

		std::cout << YELLOW << "\nPRESIDENTIAL PARDON FORM\n" << RESET << std::endl;
		PresidentialPardonForm form3("please i'm sorry");
		std::cout << form3 << "\n" << std::endl;
		charlie.executeForm(form3);
		charlie.signForm(form3);
		for (int i = charlie.getGrade(); i > form3.getSignGrade(); i--)
			charlie.incrementGrade();
		std::cout << "\n" << charlie << "\n" << std::endl;
		charlie.signForm(form3);
		for (int i = erwan.getGrade(); i > form3.getExecuteGrade(); i--)
			erwan.incrementGrade();
		std::cout << "\n" << erwan << "\n" << std::endl;
		erwan.executeForm(form3);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
