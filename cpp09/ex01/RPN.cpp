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
			if (_data.size() < 2)
				throw std::invalid_argument("wrong input: not enough operands");

			int a, b;
			b = _data.top(); _data.pop();
			a = _data.top(); _data.pop();
			if (element == "+")
			{
				checkOverflow(a, b, "+");
				checkUnderflow(a, b, "+");
				_data.push(a + b);
			}
			else if (element == "-")
			{
				checkOverflow(a, b, "-");
				checkUnderflow(a, b, "-");
				_data.push(a - b);
			}
			else if (element == "*")
			{
				checkOverflow(a, b, "*");
				checkUnderflow(a, b, "*");
				_data.push(a * b);
			}
			else
			{
				if (b != 0)
					_data.push(a / b);
				else
					throw std::invalid_argument("wrong input: divide by 0");
			}
		}
		else
		{
			long val = std::strtol(element.c_str(), NULL, 10);
			if (std::numeric_limits<int>::max() < val)
				throw std::overflow_error("overflow in input value");
			if (val < std::numeric_limits<int>::min())
				throw std::underflow_error("underflow in input value");
			_data.push(strtol(element.c_str(), NULL, 10));
		}
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

void RPN::checkOverflow(int a, int b, const std::string &operation)
{
	if (operation == "+")
	{
		if ((b > 0 && a > std::numeric_limits<int>::max() - b) || 
			(b < 0 && a < std::numeric_limits<int>::min() - b))
			throw std::overflow_error("overflow in addition");
	}
	else if (operation == "-")
	{
		// 뺄셈에서 오버플로우 조건
		if ((b < 0 && a > std::numeric_limits<int>::max() + b))
			throw std::overflow_error("overflow in subtraction");
	} else if (operation == "*")
	{
		if (a > 0)
		{
			if (b > 0 && a > std::numeric_limits<int>::max() / b)
				throw std::overflow_error("overflow in multiplication");
			if (b < 0 && b < std::numeric_limits<int>::min() / a)
				throw std::overflow_error("overflow in multiplication");
		}
		else if (a < 0)
		{
			if (b > 0 && a < std::numeric_limits<int>::min() / b)
				throw std::overflow_error("overflow in multiplication");
			if (b < 0 && a < std::numeric_limits<int>::max() / b)
				throw std::overflow_error("overflow in multiplication");
		}
	}
}


void RPN::checkUnderflow(int a, int b, const std::string &operation)
{
	if (operation == "+")
	{
		if (b < 0 && a < std::numeric_limits<int>::min() - b)
			throw std::underflow_error("underflow in addition");
	}
	else if (operation == "-")
	{
		// 뺄셈에서 언더플로우 조건
		if (b > 0 && a < std::numeric_limits<int>::min() + b)
			throw std::underflow_error("underflow in subtraction");
	}
	else if (operation == "*")
	{
		if (a > 0 && b < 0 && b < std::numeric_limits<int>::min() / a)
			throw std::underflow_error("underflow in multiplication");
		if (a < 0 && b > 0 && a < std::numeric_limits<int>::min() / b)
			throw std::underflow_error("underflow in multiplication");
	}
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
