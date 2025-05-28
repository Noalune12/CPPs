#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	{
		std::cout << "---------- BSP ----------" << std::endl << std::endl;
		{
			Point a(0, 0);
			Point b(0, 6);
			Point c(3, 4);

			std::cout << "---------- a (0,0) b(0,6) c(3,4) ----------" << std::endl;
			{
				Point point(1, 3);
				std::cout << "point(1, 3)" << (bsp(a, b, c, point) ? " is inside " : " is outside ") << "the triangle" << std::endl;
			}
			{
				Point point(0.05f, 2.5f);
				std::cout << "point(0.05, 2.5)" << (bsp(a, b, c, point) ? " is inside " : " is outside ") << "the triangle" << std::endl;
			}
			{
				Point point(0.05f, 6.5f);
				std::cout << "point(0.05, 6.5)" << (bsp(a, b, c, point) ? " is inside " : " is outside ") << "the triangle" << std::endl;
			}
			{
				std::cout << std::endl << "point on a border" << std::endl;
				Point point(0, 6);
				std::cout << "point(0.05, 6.5)" << (bsp(a, b, c, point) ? " is inside " : " is outside ") << "the triangle" << std::endl;
			}
			{
				std::cout << std::endl << "point on a summit" << std::endl;
				Point point(0, 3);
				std::cout << "point(0.05, 6.5)" << (bsp(a, b, c, point) ? " is inside " : " is outside ") << "the triangle" << std::endl;
			}
		}
		{
			Point a(0.0f, 0.0f);
			Point b(5.0f, 0.0f);
			Point c(2.5f, 0.1f);
			std::cout << "---------- a (0,0) b(5,0) c(2.5,0.1) ----------" << std::endl;
			{
				Point point(2.5f, 0.05f);
				std::cout << "point(2.5, 0.05)" << (bsp(a, b, c, point) ? " is inside " : " is outside ") << "the triangle" << std::endl;
			}
		}
		{
			Point a(0, -5);
			Point b(-3, 0);
			Point c(-3, -3);
			std::cout << "---------- a (0,-5) b(-3,0) c(-3,-3) ----------" << std::endl;
			{
				Point point(-2, -2);
				std::cout << "point(-2, -2)" << (bsp(a, b, c, point) ? " is inside " : " is outside ") << "the triangle" << std::endl;
			}
			{
				Point point(-4, -2);
				std::cout << "point(-4, -2)" << (bsp(a, b, c, point) ? " is inside " : " is outside ") << "the triangle" << std::endl;
			}
		}
	}
	return 0;
}
