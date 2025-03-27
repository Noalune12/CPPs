#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Contact desctructor called" << std::endl;
	return;
}

void	Contact::setContact(std::string firstName, std::string lastName,	std::string nickName,
	std::string phoneNumber, std::string darkestSecret) {
	_firstName = firstName;
	_lastName = lastName;
	_nickName = nickName;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
	_creationTime = time(0);
	return;
}

std::string	Contact::getFirstName(void) const {
	// std::cout << "First name: " << _firstName << std::endl;
	return (_firstName);
}

std::string	Contact::getLastName(void) const {
	// std::cout << "Last name: " << _lastName << std::endl;
	return (_lastName);
}

std::string	Contact::getNickname(void) const {
	// std::cout << "Nick name: " << _nickName << std::endl;
	return (_nickName);
}

std::string	Contact::getPhoneNumber(void) const {
	// std::cout << "Phone number: " << _phoneNumber << std::endl;
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const {
	return (_darkestSecret);
}

time_t Contact::getCreationTime(void) const {
	return (_creationTime);
}
