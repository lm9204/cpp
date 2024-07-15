#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat& ref);

		Cat&	operator=(const Cat& ref);
		Brain&	getBrain() const;
		void	setBrain(Brain& brain);
		void	makeSound() const;
	private:
		Brain*	_brain;
};

#endif