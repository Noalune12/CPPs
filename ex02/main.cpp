#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(1);
	Fixed d(1);
	Fixed e( Fixed( 2.01f ) - Fixed( 1.01f ));
	Fixed f( Fixed( 20 ) / Fixed( 0 ));

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl << std::endl;

	std::cout << "c = d = e -> " << (c == d) << ", " << (d == e) << std::endl;
	std::cout << "a > b -> " << (a > b) << std::endl;
	std::cout << "a < b -> " << (a < b) << std::endl;
	std::cout << "a != b -> " << (a != b) << std::endl;

	std::cout << "a > b = " <<Fixed::max( a, b ) << std::endl;
	std::cout << "c > d = " <<Fixed::max( c, d ) << std::endl;
	std::cout << "a < e = " <<Fixed::min( a, e ) << std::endl;
	return 0;
}
