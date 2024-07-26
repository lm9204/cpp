#include "AMateria.hpp"

AMateria::AMateria() : _type("none")
{
	
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	
}

AMateria::AMateria(const AMateria& ref)
{
	this->_type = ref._type;
}

AMateria&	AMateria::operator=(const AMateria& ref)
{
	if (this == &ref)
		return *this;

	this->_type = ref._type;
	return *this;
}

std::string	const & AMateria::getType() const
{
	return this->_type;
}
