#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point& ref);
		Point	&operator=(const Point& ref);

		Fixed	getX() const;
		Fixed	getY() const;
		void	setPoint(const float x, const float y);

	private:
		Fixed	_x;
		Fixed	_y;
};

#endif