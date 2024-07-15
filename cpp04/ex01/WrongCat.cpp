#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat()
{ 
    this->_type = "WrongCat";
    std::cout << "WrongCat Constructor is called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref)
{
    *this = ref;
    std::cout << "WrongCat Copy Constructor is called" << std::endl;
}

WrongCat&    WrongCat::operator=(const WrongCat& ref)
{
    if (this == &ref)
        return *this;

    this->_type = ref._type;
    std::cout << "WrongCat Assignment operator is called" << std::endl;
    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << "Bark" << std::endl;
}