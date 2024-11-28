#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string& filepath);
		~BitcoinExchange();

		int		validateData(std::ifstream& file);
		int		validateInputDate(std::string& date);
		int		isValidDate(int year, int date, int day);
		int		isValidDataExchangeRate(const std::string& rate);
		int		isValidInputExchangeRate(const std::string& rate);
		int		hasNonWhitespace(std::istringstream& iss);
		void	validateInput(std::ifstream& input);
		double	findData(std::string date);

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange&	operator=(const BitcoinExchange& ref);

		std::map<std::string, double>	_data;
		const std::string				_data_path;

};

#endif