#include "Point.hpp"

Point::Point( void ): _x(0), _y(0) {
	// std::cout << "Default Point constructor called" << std::endl;
}

Point::Point( const float x, const float y ): _x(x), _y(y) {
	// std::cout << "Point constructor called" << std::endl;
}

Point::~Point ( void ) {
	// std::cout << "Point destructor called" << std::endl;
}

Point::Point ( Point const& src ): _x(src._x), _y(src._y) {
	// std::cout << "Point Copy constructor called" << std::endl;
	// *this = src;
}

Point& Point::operator=(Point const& rhs) { //impossible because is const
	// std::cout << "Point operator = called" << std::endl;
	// ??????
	// this->getX() = rhs.getX().getRawBits();
	(void)rhs;
	return *this;
}

const Fixed& Point::getX( void ) const {
	return _x;
}

const Fixed& Point::getY( void ) const {
	return _y;
}

std::ostream& operator<<( std::ostream& o, Point const& name ) {
	o << "x = " << name.getX().toFloat() << ", y = " << name.getY().toFloat();
	return o;
}
