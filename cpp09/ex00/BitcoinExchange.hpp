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
		void	validInput(std::ifstream& input);
		int	isValidDate(int year, int date, int day);
		int	isValidExchangeRate(const std::string& rate);
		double	findData(std::string date);

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange&	operator=(const BitcoinExchange& ref);

		const std::string			_data_path;
		std::map<std::string, double>	_data;

};

#endif