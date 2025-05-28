#include "Point.hpp"

float areaClaculator(Point const point1, Point const point2, Point const point3 ) {
	float	x1 = point1.getX().toFloat(), x2 = point2.getX().toFloat(), x3 = point3.getX().toFloat();
	float	y1 = point1.getY().toFloat(), y2 = point2.getY().toFloat(), y3 = point3.getY().toFloat();
	float	area = ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / 2;
	// if (area < 0)
	// 	return (-area);
	return ((area < 0) ? -area : area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	float area1 = areaClaculator(a, b, point);
	float area2 = areaClaculator(a, c, point);
	float area3 = areaClaculator(b, c, point);
	float totalArea = areaClaculator(a, b, c);
	// if (area1 == 0 || area2 == 0 || area3 == 0)
	// 	return (false);
	// if (totalArea == area1 + area2 + area3)
	// 	return (true);
	return ((area1 == 0 || area2 == 0 || area3 == 0) ? false : (totalArea == area1 + area2 + area3));
}
