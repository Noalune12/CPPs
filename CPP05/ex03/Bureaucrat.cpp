#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name("Unknown"), _grade(150) {
	// std::cout << "✨ Bureaucrat default constructor called ✨" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	// std::cout << "✨ Bureaucrat constructor called ✨" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src): _name(src._name), _grade(src._grade) {
	// std::cout << "📄 Bureaucrat copy constructor called 📄" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "🧹 Bureaucrat deconstructor called 🧹" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& src) {
	if (this != &src)
		_grade = src._grade;
	// std::cout << "🟰 Bureaucrat operator called 🟰" << std::endl;
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (const std::ios_base::failure& e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because of a file error: " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& name) {
	o << name.getName() << ", bureaucrat grade " << name.getGrade();
	return o;
}

