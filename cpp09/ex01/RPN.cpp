#include <iostream>
#include <sstream>
#include <exception>
#include <cstdlib>

#include "RPN.hpp"

RPN::RPN(std::string arg)
{
	std::stringstream	ss(arg);
	std::string			element;

	while (ss >> element)
	{
		if (!checkSymbol(element))
			throw std::invalid_argument("wrong input found");

		if (isSymbol(element))
		{
			int a, b;
			b = _data.top(); _data.pop();
			a = _data.top(); _data.pop();
			if (element == "+")
				_data.push(a + b);
			else if (element == "-")
				_data.push(a - b);
			else if (element == "*")
				_data.push(a * b);
			else
			{
				if (b != 0)
					_data.push(a / b);
				else
					throw std::invalid_argument("wrong input: divide by 0");
			}
		}
		else
			_data.push(strtol(element.c_str(), NULL, 10));
	}
}

RPN::~RPN() {}

void	RPN::run()
{
	if (_data.size() == 1)
		std::cout << _data.top() << "\n";
	else
		throw std::invalid_argument("wrong input: too many elements");
}

int	RPN::checkSymbol(std::string element)
{
	if (element.size() == 1 && isSymbol(element))
		return (1);

	for (size_t i = 0; i < element.size(); ++i)
	{
		if (!isdigit(element[i]))
			return (0);
	}
	return (1);
}

int RPN::isSymbol(std::string element)
{
	if (element == "*" ||
	element == "/" ||
	element == "+" ||
	element == "-")
		return (1);
	return (0);
}
