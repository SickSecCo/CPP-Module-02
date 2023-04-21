#include "Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::Point(float const num1, float const num2): x(num1), y(num2){}

Point::~Point() {}

Point::Point(Point const& src): x(src.x), y(src.y) {}

Point &Point::operator=(Point const& src)
{
	(void) src;
	return (*this);
}

float Point::getX() const {
	return (this->x.toFloat());
}

float Point::getY() const {
	return (this->y.toFloat());
}

