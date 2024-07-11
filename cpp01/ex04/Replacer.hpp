
#ifndef REPLACER_HPP
# define REPLACER_HPP
# include <string>
# include <iostream>
# include <fstream>

class Replacer
{
    private:
        std::string _filename;
        std::string _origin;
        std::string _replace;
    public:
        Replacer();
        Replacer(std::string filename, std::string s1, std::string s2);
        bool    execute();
        ~Replacer();

};

#endif