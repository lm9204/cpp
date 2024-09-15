#include "Data.hpp"

Data::Data()
{

}

Data::Data(std::string name) : _name(name) {}

Data::Data(const Data& ref)
{
	*this = ref;
}

Data&	Data::Data::operator=(const Data& ref)
{
	if (this == &ref)
		return *this;

	this->_name = ref.getName();
	return *this;
}

Data::~Data()
{

}

std::string	Data::getName() const
{
	return _name;
}

void	Data::setName(std::string name)
{
	_name = name;
}