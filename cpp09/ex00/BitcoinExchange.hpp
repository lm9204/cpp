#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string filepath);
		~BitcoinExchange();

		int		validData(std::ifstream& file);
		int		isValidDate(int year, int date, int day);
		int		isValidExchangeRate(const std::string& rate);
		void	validInput(std::ifstream& input);
		double	findData(std::string date);

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange&	operator=(const BitcoinExchange& ref);

		std::map<std::string, double>	_data;
		const std::string				_data_path;

};

#endif