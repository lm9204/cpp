#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap jason("jason");
    ScavTrap scav;
    ClapTrap jack("jack");
    ScavTrap matt("matt");

    matt.attack("jack");
    jack.takeDamage(11);
    jack.beRepaired(10);
    scav.guardGate();
}