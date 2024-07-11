#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon      _weapon;

    public:
        HumanB();
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon& type);
        void attack() const;
};

#endif