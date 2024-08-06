#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap jason("Jason");
    ScavTrap scav;
    ScavTrap jack("Jack");

    jason.attack("Someone");
    jason.takeDamage(2);
    scav.attack("Jason");
    jack.attack("scav");
    scav.guardGate();
    scav.takeDamage(10);
    scav.attack("Jason");
    scav.beRepaired(10);
    scav.takeDamage(101);
    scav.takeDamage(11);
    scav.attack("Jason");
    scav.beRepaired(100);
    jack.guardGate();
}