#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

AForm::AForm(): _name("Unknown Form"), _signed(false), _signGrade(150), _executeGrade(150) {
	// std::cout << "✨ Form default constructor called ✨" << std::endl;
}

AForm::AForm(std::string name, int sign, int exec): _name(name), _signed(false), _signGrade(sign), _executeGrade(exec) {
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	// std::cout << "✨ Form constructor called ✨" << std::endl;
}

AForm::AForm(AForm const& src): _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _executeGrade(src._executeGrade) {
	// std::cout << "📄 Form copy constructor called 📄" << std::endl;
}

AForm::~AForm() {
	// std::cout << "🧹 Form deconstructor called 🧹" << std::endl;
}

AForm& AForm::operator=(AForm const& src) {
	if (this != &src) {
		_name = src._name;
		_signed = src._signed;
		_signGrade = src._signGrade;
		_executeGrade = src._executeGrade;
	}
	// std::cout << "🟰 Form operator called 🟰" << std::endl;
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecuteGrade() const {
	return _executeGrade;
}

void AForm::beSigned(Bureaucrat const& name) {
	if (name.getGrade() > this->getSignGrade()) {
		std::cout << name.getName() << " couldn’t sign " << this->getName() << " because ";
		throw GradeTooLowException();
	}
	// if (this->getSigned() == true) {
	// 	std::cout << name.getName() << " couldn’t sign " << this->getName() << " because it is already signed" << std::endl;
	// 	return;
	// }
	_signed = true;
	std::cout << name.getName() << " signed " << this->getName() << std::endl;
}

void AForm::execute(Bureaucrat const & executor) const { // add message
	if (_signed == false)
		throw FormIsNotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
	executeForm();
}


const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormIsNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& o, AForm const& name) {
	o << "Form " << name.getName() << ": \n- is signed : " << (name.getSigned() ? "yes\n" : "no\n") << "- minimum grade needed to sign: " << name.getSignGrade() << "\n- minimum grade to execute: " << name.getExecuteGrade();
	return o;
}
