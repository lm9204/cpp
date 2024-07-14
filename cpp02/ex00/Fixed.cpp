#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _fixedN(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed&	Fixed::operator=(const Fixed& ref)
{
	if (this ==& ref)
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