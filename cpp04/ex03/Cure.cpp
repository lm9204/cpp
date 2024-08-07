#include <iostream>
#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(const Cure& ref)
{
	this->_type = ref._type;
}

Cure::~Cure()
{

}

Cure&	Cure::operator=(const Cure& ref)
{
	if (this == &ref)
		return *this;
	
	this->_type = ref._type;
	return *this;
}

Cure*	Cure::clone() const
{
	Cure* clone = new Cure();
	return clone;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}