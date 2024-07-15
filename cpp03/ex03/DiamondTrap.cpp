#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), _name("DiamondTrap")
{
    this->_hit = FragTrap::_hit;
    this->_energy = ScavTrap::_energy;
    this->_damage = FragTrap::_damage;
    std::cout << "Diamond Constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{

    this->_hit = FragTrap::_hit;
    this->_energy = ScavTrap::_energy;
    this->_damage = FragTrap::_damage;
    std::cout << "Diamond Constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref) : ClapTrap(ref), ScavTrap(ref), FragTrap(ref)
{
    this->_name = ref._name;
    this->_hit = ref._hit;
    this->_energy = ref._energy;
    this->_damage = ref._damage;
    std::cout << "Diamond Copy Constructor is called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Desturctor is called" << std::endl;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& ref)
{
    if (this == &ref)
        return *this;
    this->_name = ref._name;
    this->_hit = ref._hit;
    this->_energy = ref._energy;
    this->_damage = ref._damage;
    std::cout << "DiamondTrap Assignment operator is called" << std::endl;
    return *this;
}

void    DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap: " << this->_name << ", ClapTrap: " << ClapTrap::_name << std::endl;
}