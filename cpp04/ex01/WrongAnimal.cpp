#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{

    std::cout << "WrongAnimal Destructor operator is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
    *this = ref;
    std::cout << "WrongAnimal Copy Constructor is called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
    if (this == &ref)
        return *this;
    std::cout << "WrongAnimal Assignment operator is called" << std::endl;
    this->_type = ref._type;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal" << std::endl;
}