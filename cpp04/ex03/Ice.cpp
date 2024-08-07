#include <iostream>
#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(const Ice& ref)
{
	this->_type = ref._type;
}

Ice::~Ice()
{

}

Ice&	Ice::operator=(const Ice& ref)
{
	if (this == &ref)
		return *this;

	this->_type = ref._type;
	return *this;
}

Ice*	Ice::clone() const
{
	Ice* clone = new Ice();
	return clone;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}