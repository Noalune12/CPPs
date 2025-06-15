#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137), _target("Unknown") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src): AForm(src), _target(src._target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src) {
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::executeForm(Bureaucrat const & executor) const {
    std::cout << executor.getName() << " executed " << getName() << std::endl;
}