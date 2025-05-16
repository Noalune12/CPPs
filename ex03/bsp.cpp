#include "Point.hpp"

float areaClaculator(Point const point1, Point const point2, Point const point3 ) {
	// float	area = (((point1.getX().toFloat() * (point2.getY().toFloat() - point3.getY().toFloat()))
	// 				- (point1.getY().toFloat() * (point2.getX().toFloat() - point3.getX(). toFloat()))
	// 				+ (point2.getX().toFloat() * point3.getY().toFloat() - point2.getY().toFloat() * point3.getX(). toFloat()))
	// 				/ 2);
	float	area = (((point1.getX().toFloat() * (point2.getY().toFloat() - point3.getY().toFloat()))
					+ (point2.getX().toFloat() * (point3.getY().toFloat() - point1.getY(). toFloat()))
					+ (point3.getX().toFloat() * (point1.getY().toFloat() - point2.getY(). toFloat())))
					/ 2);
	if (area < 0)
		return (-area);
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	std::cout << "Point a = " << a << std::endl;
	std::cout << "Point b = " << b << std::endl;
	std::cout << "Point c = " << c << std::endl;
	std::cout << "Point point = " << point << std::endl;

	float area1 = areaClaculator(a, b, point);
	float area2 = areaClaculator(a, c, point);
	float area3 = areaClaculator(b, c, point);
	float totalArea = areaClaculator(a, b, c);

	std::cout << "Area a, b, point = " << area1 << std::endl;
	std::cout << "Area a, c, point = " << area2 << std::endl;
	std::cout << "Area b, c, point = " << area3 << std::endl;
	std::cout << "Area = " << totalArea << std::endl;
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	if (totalArea == area1 + area2 + area3)
		return (true);
	return (false);
}
