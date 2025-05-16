#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point {

	public:
		Point( void );
		Point( const float x, const float y );
		Point ( Point const& src );
		~Point( void );

		Point& operator=(Point const& rhs);
		const Fixed& getX( void ) const;
		const Fixed& getY( void ) const;


	private:
		const Fixed _x;
		const Fixed _y;
};

std::ostream & operator<<( std::ostream& o, Point const& name );

#endif
