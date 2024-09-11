#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

class ScalarConverter
{
	public:
		static void	convert(const std::string& input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& ref);
		ScalarConverter&	operator=(const ScalarConverter& ref);
		~ScalarConverter();
	
};


#endif