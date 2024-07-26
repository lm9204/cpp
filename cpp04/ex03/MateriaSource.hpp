#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& ref);
		MateriaSource&	operator=(const MateriaSource& ref);

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const & type);

};

#endif