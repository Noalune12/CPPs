#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook constructor called" << std::endl;
	_index = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook destructor called" << std::endl;
	return;
}

int	PhoneBook::getIndex(void) const {
	// std::cout << "Index: " << _index << std::endl;
	return (_index);
}
