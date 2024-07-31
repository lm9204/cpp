#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap")
{
    this->_hit = this->_base_hit;
    this->_energy = this->_base_energy;
    this->_damage = this->_base_damage;
    std::cout << "ClapTrap Constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{

    this->_hit = this->_base_hit;
    this->_energy = this->_base_energy;
    this->_damage = this->_base_damage;
    std::cout << "ClapTrap Constructor is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
    *this = ref;
    std::cout << "ClapTrap Copy Constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor is called" << std::endl;
}

ClapTrap&    ClapTrap::operator=(const ClapTrap& ref)
{
    if (this == &ref)
        return *this;

    this->_name = ref._name;
    this->_hit = ref._hit;
    this->_energy = ref._energy;
    this->_damage = ref._damage;
    std::cout << "ClapTrap Assignment Operator is called" << std::endl;
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_hit <= 0 && this->_energy != 0)
    {
        std::cout << this->_name << " should be repair!!" << std::endl;;
        return;
    }
    if (this->_energy == 0)
    {
        std::cout << this->_name << " hasn't enough Energy!!!" << std::endl;
        return;
    }

    std::cout << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
    this->_energy--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->_name << " is hit, " << amount << "points of damage!" << std::endl;
    if (amount > this->_hit)
        this->_hit = 0;
    else
        this->_hit -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit <= 0)
    {
        std::cout << "it's seems not working anymore :(" << std::endl;
        return;
    }
    if (this->_energy == 0)
    {
        std::cout << this->_name << " hasn't enough Energy!!!" << std::endl;
        return;
    }

    std::cout << this->_name << " is repaired!!" << std::endl;
    this->_energy--;
    this->_hit += amount;
}
