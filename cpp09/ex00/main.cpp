#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		return (1);

	try
	{
		BitcoinExchange btc = BitcoinExchange(static_cast<std::string>(argv[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}