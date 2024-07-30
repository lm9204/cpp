#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);
Fixed   vsign(Point const a, Point const b, Point const c);

int main( void )
{
	Point p1(2, 2);
	Point p2(1, 4);
	Point p3(2.2, 2.2);


	Point a(1, 3);
	Point b(3, 3);
	Point c(2, 1);

	std::cout << "p1: " << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;
	std::cout << "p2: " << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;
	std::cout << "p3: " << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;
}