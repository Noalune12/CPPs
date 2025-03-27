#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Contact desctructor called" << std::endl;
	return;
}

void	Contact::setContact(int *id, std::string firstName, std::string lastName) {
	this->id = *id;
	(*id)++;
	this->firstName = firstName;
	this->lastName = lastName;
	return;
}
