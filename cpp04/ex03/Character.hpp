#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character& ref);
		~Character();

		Character&	operator=(const Character& ref);
		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		AMateria*	_inventory[4];
		std::string	_name;
		int			_idx;
};

#endif
