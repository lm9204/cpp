#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _fixedN(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedN(n << _fract_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatN) : _fixedN(roundf(floatN * (1 << _fract_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed	&Fixed::operator=(const Fixed &ref)
{
	if (this == &ref)
		return *this;

	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedN = ref.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedN;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedN = raw;
}

int		Fixed::toInt(void) const
{
	return _fixedN >> _fract_bits;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedN) / (1 << _fract_bits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}