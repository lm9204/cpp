#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& ref);
        ~FragTrap();

        FragTrap&   operator=(const FragTrap& ref);
        void        highFivesGuys(void) const;
        
    private:
        static const unsigned int   _base_hit       = 100;
        static const unsigned int   _base_energy    = 100;
        static const unsigned int   _base_damage    = 30;
};

#endif