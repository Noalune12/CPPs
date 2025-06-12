#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(): _name("Unknown"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooLowException();
	if (grade > 150)
		throw GradeTooHighException();
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src): _name(src._name), _grade(src._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat deconstructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& src) {
	if (this != &src) {
		_name = src._name;
		_grade = src._grade;
	}
	std::cout << "Bureaucrat operator called" << std::endl;
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade(int score) {
	if (_grade - score < 1)
		throw GradeTooHighException();
	_grade -= score;
}

void Bureaucrat::decrementGrade(int score) {
	if (_grade + score > 150)
		throw GradeTooLowException();
	_grade += score;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& name) {
	o << name.getName() << ", bureaucrat grade " << name.getGrade();
	return o;
}

