#include "Fixed.hpp"

#include <iostream>
#include <cmath>

const int Fixed::_bit = 8;

Fixed::Fixed( void ) : _val( 0 ) {
	// std::cout << "Default Fixed constructor called" << std::endl;
}

Fixed::Fixed( int const n ) {
	// std::cout << "Fixed Int constructor called" << std::endl;
	_val = n << _bit;
}

Fixed::Fixed( float const f ) {
	// std::cout << "Fixed Float constructor called" << std::endl;
	_val = static_cast<int>(roundf(f * (1 << _bit)));
}


Fixed::Fixed( Fixed const& src ) {
	// std::cout << "Fixed Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void ) {
	// std::cout << "Fixed destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
	this->_val = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const& rhs) const {
	return this->toFloat() + rhs.toFloat();
}

Fixed Fixed::operator-(Fixed const& rhs) const {
	return this->toFloat() - rhs.toFloat();
}

Fixed Fixed::operator*(Fixed const& rhs) const {
	return this->toFloat() * rhs.toFloat();
}

Fixed Fixed::operator/(Fixed const& rhs) const {
	if (rhs.toFloat() == 0) {
		std::cout << "You can't divide by 0, numerator is the value assigned." << std::endl;
		return this->toFloat();
	}
	return this->toFloat() / rhs.toFloat();
}
Fixed&	Fixed::operator++( void ) {
	_val++;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed temp = *this;
	++_val; // or ++*this;
	return temp;
}

Fixed&	Fixed::operator--( void ) {
	_val--;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed temp = *this;
	--_val; // or --*this;
	return temp;
}

bool	Fixed::operator==( const Fixed& rhs ) {
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=( const Fixed& rhs ) {
	return (this->toFloat() != rhs.toFloat());
}

bool	Fixed::operator>( const Fixed& rhs ) {
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator<( const Fixed& rhs ) {
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator>=( const Fixed& rhs ) {
	return (this->toFloat() >= rhs.toFloat());
}

bool	Fixed::operator<=( const Fixed& rhs ) {
	return (this->toFloat() <= rhs.toFloat());
}

Fixed& Fixed::min( Fixed& lhs, Fixed& rhs) {
	if (lhs.toFloat() >= rhs.toFloat())
		return (rhs);
	else
		return (lhs);
}

const Fixed& Fixed::min( const Fixed& lhs, const Fixed& rhs) {
	if (lhs.toFloat() >= rhs.toFloat())
		return (rhs);
	else
		return (lhs);
}

Fixed& Fixed::max( Fixed& lhs, Fixed& rhs) {
	if (lhs.toFloat() <= rhs.toFloat())
		return (rhs);
	else
		return (lhs);
}

const Fixed& Fixed::max( const Fixed& lhs, const Fixed& rhs) {
	if (lhs.toFloat() <= rhs.toFloat())
		return (rhs);
	else
		return (lhs);
}

int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void Fixed::setRawBits( int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_val = raw;
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>(_val) / (1 << _bit);
}

int	Fixed::toInt( void ) const {
	return _val >> _bit;
}

std::ostream & operator<<( std::ostream& o, Fixed const& name ) {
	o << name.toFloat();
	return o;
}
