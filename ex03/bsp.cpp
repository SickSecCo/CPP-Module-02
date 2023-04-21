#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1 = 0.0;
	float d2 = 0.0;
	float d3 = 0.0;
	float res1 = 0.0;
	float res2 = 0.0;

	d1 = (point.getX() - a.getX()) * (c.getY() - a.getY()) - (point.getY() - a.getY()) * (c.getX() - a.getX());
	d2 = (a.getX() - point.getX()) * (b.getY() - a.getY()) - (a.getY() - point.getY()) * (b.getX() - a.getX());
	d3 = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
	res1 = d1 / d3;
	res2 = d2 / d3;
	if (res1 > 0 && res2 > 0 && (res1 + res2) < 1)
		return (true);
	else
		return (false);
}