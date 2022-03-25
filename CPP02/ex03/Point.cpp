#include "Point.hpp"

/*
(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)
(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)
*/

Point::Point() {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::~Point() {}

Point::Point(Point const &point)
{
	*this = point;
}

Point& Point::operator= (const Point &point )
{
	if (this == &point)
		return (*this);
	Fixed *tmpX = const_cast<Fixed *>(&_x);
	Fixed *tmpY = const_cast<Fixed *>(&_y);
	*tmpX = point.getX();
	*tmpY = point.getY();

	return (*this);
}

float Point::getX(void) const
{
	return (this->_x.toFloat());
}

float Point::getY(void) const
{
	return (this->_y.toFloat());
}

Fixed check(Point const a, Point const b, Point const c)
{
	Fixed buf ((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
	if (buf < 0)
		buf = buf * -1;
	return (buf);
}

bool bsp (Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = check(a, b, c);
	Fixed i (check(a, b, point));
	Fixed j (check(b, c, point));
	Fixed k (check(c, a, point));
	if (i == 0 || j == 0 || k == 0 || abc == 0)
		return (false);
	// std::cout << abc << " " << (i + j + k) << std::endl;
	return (abc == i + j + k);
}