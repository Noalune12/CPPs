#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5), _target("Unknown") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src): AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& src) {
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void PresidentialPardonForm::executeForm() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
