#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y)
{
    this->_x = Fixed(x);
    this->_y = Fixed(y);
}

Point::~Point() {}

Point::Point(const Point& ref)
{
    *this = ref;
}

Point   &Point::operator=(const Point& ref)
{
    if (this == &ref)
        return *this;

    this->_x = ref._x;
    this->_y = ref._y;
    return *this;
}

Fixed   Point::getX() const
{
    return this->_x;
}

Fixed   Point::getY() const
{
    return this->_y;
}

void    Point::setPoint(const float x, const float y)
{
    this->_x = Fixed(x);
    this->_y = Fixed(y);
}
