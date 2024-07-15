#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& ref);

        Cat&    operator=(const Cat& ref);
        void    makeSound() const;
};

#endif