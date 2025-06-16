#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

Intern::Intern() {}

Intern::Intern(Intern const& src) {
	(void)src;
}

Intern::~Intern() {}

Intern& Intern::operator=(Intern const& src) {
	(void)src;
	return *this;
}

AForm* Intern::createShrubberyForm(std::string target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(std::string target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(std::string target) const {
	return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(std::string name, std::string target) const {
	std::string formName[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	AForm* (Intern::*formCreation[3])(std::string) const = { &Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm };
	for (int i = 0; i < 3; i++) {
		if (formName[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formCreation[i])(target);
		}
	}
	throw std::runtime_error("Error creating form: " + name + " is not a known category!");
	// std::cout << "Error creating form: " << name << " is not a known category!" << std::endl;
	// return (NULL);
}
