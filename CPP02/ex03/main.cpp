#include "Point.hpp"

int main( void )
{
	Point a( -2.3f, 4.1f );
	Point b( -3.5f, 1.1f );
	Point c( 2.6f, 3.0f );
	Point point1( -1.1f, 3.0f );
	Point point2(1.0f, 2.0f);
	
	std::cout << bsp(a, b, c, point1) << std::endl;
	std::cout << bsp(a, b, c, point2) << std::endl;
	return 0;
}
