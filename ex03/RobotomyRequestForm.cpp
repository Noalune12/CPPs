#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45), _target("Unknown") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src): AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& src) {
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void RobotomyRequestForm::executeForm() const {
	std::cout << "Brrrrrrrrr... Vrrrrrrrrrr... Bzzzzzzzzzz!" << std::endl;
	std::srand(time(0));
	int random = rand();
	// std::cout << random << std::endl;
	if (random % 2 == 0)
		std::cout << _target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << "Robotomy has failed!" << std::endl;
}
