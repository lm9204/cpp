#include "Replacer.hpp"

Replacer::Replacer() {}

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
: _filename(filename), _origin(s1), _replace(s2) {}

Replacer::~Replacer() {}

bool    Replacer::execute()
{
    std::ifstream input(this->_filename.c_str(), std::ios_base::in);
    std::ofstream output(this->_filename.append(".replace").c_str(), std::ios_base::out);

    std::string str;

    // no file
    if (!input.is_open() || !output.is_open())
        return (false);
    bool    isFirst = false;
    while (std::getline(input, str))
    {
        if (isFirst)
            output << std::endl;
        isFirst = true;
        size_t  pos = 0;
        while ((pos = str.find(this->_origin, pos)) != std::string::npos)
        {
            str.erase(pos, this->_origin.length());
            str.insert(pos, this->_replace);
            pos += this->_replace.length();
        }
        output << str;
    }
    input.close();
    output.close();
    return (true);
}