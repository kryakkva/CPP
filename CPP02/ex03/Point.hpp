#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(float x, float y);
	Point(const Point &point);
	Point& operator= (const Point &point);

	float getX (void) const;
	float getY (void) const;
	~Point();
};

bool bsp (Point const a, Point const b, Point const c, Point const point);
