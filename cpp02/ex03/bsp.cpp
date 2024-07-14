#include "Point.hpp"

Fixed   vsign(Point const a, Point const b, Point const c)
{
    return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (a.getY() - c.getY()) * (b.getX() - c.getX());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed   d1 = vsign(point, a, b);
	Fixed   d2 = vsign(point, b, c);
	Fixed   d3 = vsign(point, c, a);

    bool    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}