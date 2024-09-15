#include <iostream>
#include <iomanip>
#include <climits>
#include "ScalarConverter.hpp"

static bool	isNan(const std::string& input)
{
	if (input == "nan" || input == "nanf")
		return true;
	return false;
}

static bool isInf(const std::string& input)
{
	if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff"
	|| input == "-inf" || input == "-inff")
		return true;
	return false;
}

void	ScalarConverter::convert(const std::string& input)
{
	double val;
	try
	{
		
		char *ptr = NULL;
		val = std::strtod(input.c_str(), &ptr);
		if (!isNan(input) && !isInf(input))
		{
			bool dotflag = false, signflag = false;
			size_t dotidx;
			for (size_t i = 0 ; i < input.length(); ++i)
			{
				if (!signflag && input.length() - 1 != 0 && i == 0 && (input[0] == '-' || input[0] == '+'))
				{
					signflag = true;
					continue;
				}
				if (!dotflag && input[i] == '.')
				{
					dotflag = true;
					dotidx = i;
				}
				else if ((!(i != 0 && i == input.length() - 1 && input[i] == 'f') && !std::isdigit(input[i]))
				|| (signflag && i == 1 && input[i] == 'f'))
					throw std::exception();
			}
			if (dotflag && (dotidx == 0 || dotidx == input.length() - 1))
				throw std::exception();
		}
		if (val == 0.0
			&& input[0] != '-' && input[0] != '+' && !std::isdigit(input[0])
			&& *ptr && std::strcmp(ptr, "f"))
			throw std::exception();
	}
	catch(...)
	{
		std::cerr << "Convert Fail" << '\n';
		return ;
	}
	
	std::cout << "char: ";
	(std::isnan(val) || std::isinf(val)
	|| val < 0 || std::numeric_limits<char>::max() < val)
		? std::cout << "impossible\n" : (std::isprint(static_cast<char>(val)))
		? std::cout << "'" << static_cast<char>(val) << "'\n" : std::cout << "Non displayable\n";

	std::cout << "int: ";
	(std::isnan(val) || std::isinf(val)
	|| val < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < val)
		? std::cout << "impossible\n" : std::cout << static_cast<int>(val) << "\n";

	if (std::isnan(val) || std::isinf(val))
	{
		std::cout <<
		"float: " << std::showpos << static_cast<float>(val) << "f" << "\n" <<
		"double: " << val << "\n";
		return ;
	}

	std::cout << "float: ";
	(static_cast<float>(val) == static_cast<int64_t>(static_cast<float>(val)))
		? std::cout << static_cast<float>(val) << ".0f\n"
		: std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(val) << "f\n";

	std::cout << "double: ";
	(static_cast<double>(val) == static_cast<int64_t>(static_cast<double>(val)))
		? std::cout << static_cast<double>(val) << ".0\n"
		: std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<double>(val) << "\n";
}