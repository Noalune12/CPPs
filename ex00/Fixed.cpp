#include "Fixed.hpp"

#include <iostream>

const int Fixed::_bit = 8;

Fixed::Fixed( void ) : _val( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
	this->_val = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void Fixed::setRawBits( int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_val = raw;
}
