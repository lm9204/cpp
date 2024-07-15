#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& ref);

        ClapTrap&   operator=(const ClapTrap& ref);
        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        void        setDamage(unsigned int amount);

    protected:
        std::string     _name;
        unsigned int    _hit;
        unsigned int    _energy;
        unsigned int    _damage;

    private:
        static const unsigned int   _base_hit       = 10;
        static const unsigned int   _base_energy    = 10;
        static const unsigned int   _base_damage    = 0;

};

#endif