#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& ref);

        Dog&    operator=(const Dog& ref);
        void    makeSound() const;
    private:
        Brain*  _brain;
};

#endif