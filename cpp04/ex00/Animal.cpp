#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor is called" << std::endl;
}

Animal::~Animal()
{

    std::cout << "Animal Destructor operator is called" << std::endl;
}

Animal::Animal(const Animal& ref)
{
    *this = ref;
    std::cout << "Animal Copy Constructor is called" << std::endl;
}

Animal& Animal::operator=(const Animal& ref)
{
    if (this == &ref)
        return *this;
    std::cout << "Animal Assignment operator is called" << std::endl;
    this->_type = ref._type;
    return *this;
}

std::string Animal::getType() const
{
    return this->_type;
}

void    Animal::makeSound() const
{
    std::cout << "Animal" << std::endl;
}