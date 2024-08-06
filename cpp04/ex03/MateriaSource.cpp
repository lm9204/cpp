#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
	for (int i = 0; i < 4; ++i)
		this->_m[i] = ref._m[i];
}

MateriaSource::~MateriaSource()
{

}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ref)
{
	if (this == &ref)
		return *this;

	for (int i = 0; i < 4; ++i)
		this->_m[i] = ref._m[i];
	return *this;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4;  ++i)
	{
		if (!this->_m[i])
		{
			this->_m[i] = materia->clone();
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4 && this->_m[i] != 0; ++i)
	{
		if (this->_m[i]->getType() == type)
			return this->_m[i]->clone();
	}
	return (0);
}