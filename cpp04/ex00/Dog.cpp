#include <iostream>
#include "Dog.hpp"

Dog::Dog()
{ 
    this->_type = "Dog";
    std::cout << "Dog Constructor is called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor is called" << std::endl;
}

Dog::Dog(const Dog& ref) : Animal(ref)
{
    *this = ref;
    std::cout << "Dog Copy Constructor is called" << std::endl;
}

Dog&    Dog::operator=(const Dog& ref)
{
    if (this == &ref)
        return *this;

    this->_type = ref._type;
    std::cout << "Dog Assignment operator is called" << std::endl;
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}