#include "Point.hpp"

int main( void ) {
	
	Point point1(1, 1);
	Point point2(4, 2);
	Point point3(5, -15);

	Point point4(3, 2);

	std::cout << bsp(point1, point2, point3, point4) << std::endl;

	Point point5(4, -5);

	std::cout << bsp(point1, point2, point3, point5) << std::endl;

	return (0);
}