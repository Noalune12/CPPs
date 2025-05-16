#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	{
		std::cout << "---------- TEST POINT ----------" << std::endl << std::endl;
		Point test;
		std::cout << " test = " << test << std::endl << std::endl;
		Point test2(1.02f, 2.05f);
		std::cout << " test2 = " << test2 << std::endl << std::endl;
		Point test3 = test2;
		std::cout << " test3 = " << test3 << std::endl << std::endl;
		Point test4(test2);
		std::cout << " test4 = " << test4 << std::endl << std::endl;
	}
	{
		std::cout << "---------- BSP ----------" << std::endl << std::endl;
		// Point a(0, 0);
		// Point b(10, 0);
		// Point c(5, 10);
		// Point point(-0.1f, -0.1f);
		Point a(0, 0);
		Point b(10, 0);
		Point c(5.0f, 0.1f);
		Point point(5.0f, 0.05f);
		if (bsp(a, b, c, point) == true)
			std::cout << "point -> " << point << " is inside the triangle" << std::endl;
		else
			std::cout << "point -> " << point << " is not inside the triangle" << std::endl;
	}
	return 0;
}


/*


	y
x       . . . . . . . . .
		. a x x x x b . .
		. x . P . x . . .
		. x . . x . . . .
		. x . x . . . . .
		. x x . . . . . .
		. c . . . . . . .
*/
