#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& ref);
		~Ice();
		Ice&	operator=(const Ice& ref);
		Ice*	clone() const;
		void	use(ICharacter& target);
};

#endif