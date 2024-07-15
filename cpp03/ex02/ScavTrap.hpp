#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& ref);
        ~ScavTrap();

        ScavTrap&   operator=(const ScavTrap& ref);
        void        attack(const std::string& target);
        void        guardGate() const;

    private:
        static const unsigned int   _base_hit       = 100;
        static const unsigned int   _base_energy    = 50;
        static const unsigned int   _base_damage    = 20;
};

#endif