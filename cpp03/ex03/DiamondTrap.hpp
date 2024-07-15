#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& ref);
        ~DiamondTrap();

        DiamondTrap&    operator=(const DiamondTrap& ref);
        void            attack(const std::string& target);
        void            whoAmI() const;
    private:
        std::string _name;
};

#endif