#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hit(10), _energy(10), _damage(0)
{
    std::cout << "Constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _damage(0)
{

    std::cout << "Constructor is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
    *this = ref;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor is called" << std::endl;
}

ClapTrap&    ClapTrap::operator=(const ClapTrap& ref)
{
    if (this == &ref)
        return *this;

    this->_name = ref._name;
    this->_hit = ref._hit;
    this->_energy = ref._energy;
    this->_damage = ref._damage;
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_hit == 0 && this->_energy != 0)
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
    //target->_hit -= this->_damage;
    this->_energy--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->_name << " is hit, " << amount << "points of damage!" << std::endl;
    this->_hit -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit == 0)
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

void    ClapTrap::setDamage(unsigned int amount)
{
    this->_damage = amount;
}