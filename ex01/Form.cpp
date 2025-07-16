#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

Form::Form(): _name("Unknown Form"), _signed(false), _signGrade(150), _executeGrade(150) {
	// std::cout << "✨ Form default constructor called ✨" << std::endl;
}

Form::Form(std::string name, int sign, int exec): _name(name), _signed(false), _signGrade(sign), _executeGrade(exec) {
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
	// std::cout << "✨ Form constructor called ✨" << std::endl;
}

Form::Form(Form const& src): _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _executeGrade(src._executeGrade) {
	// std::cout << "📄 Form copy constructor called 📄" << std::endl;
}

Form::~Form() {
	// std::cout << "🧹 Form deconstructor called 🧹" << std::endl;
}

Form& Form::operator=(Form const& src) {
	if (this != &src) {
		_name = src._name;
		_signed = src._signed;
		_signGrade = src._signGrade;
		_executeGrade = src._executeGrade;
	}
	// std::cout << "🟰 Form operator called 🟰" << std::endl;
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecuteGrade() const {
	return _executeGrade;
}

void Form::beSigned(Bureaucrat const& name) {
	if (name.getGrade() > this->getSignGrade()) {
		throw GradeTooLowException();
	}
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& o, Form const& name) {
	o << "Form " << name.getName() << ": \n- is signed: " << (name.getSigned() ? "yes\n" : "no\n") << "- minimum grade needed to sign: " << name.getSignGrade() << "\n- minimum grade to execute: " << name.getExecuteGrade();
	return o;
}
