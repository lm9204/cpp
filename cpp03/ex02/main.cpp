#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap jason("jason");
    ScavTrap scav;
    ClapTrap jack("jack");
    ScavTrap matt("matt");
    FragTrap frog("frog");

    matt.attack("jack");
    jack.takeDamage(11);
    jack.beRepaired(10);
    scav.guardGate();
    frog.attack("someone");
    frog.highFivesGuys();
    frog.takeDamage(50);
    frog.beRepaired(50);
}