#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& ref);
        ~WrongAnimal();

        WrongAnimal& operator=(const WrongAnimal& ref);
        std::string     getType() const;
        virtual void    makeSound() const;
    
    protected:
        std::string _type;

};

#endif