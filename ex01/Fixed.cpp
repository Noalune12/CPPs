/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 07:31:32 by lbuisson          #+#    #+#             */
/*   Updated: 2025/05/28 07:31:34 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

const int Fixed::_bit = 8;

Fixed::Fixed( void ) : _val( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const n ) {
	std::cout << "Int constructor called" << std::endl;
	_val = n << _bit;
}

Fixed::Fixed( float const f ) {
	std::cout << "Float constructor called" << std::endl;
	_val = static_cast<int>(roundf(f * (1 << _bit)));
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
