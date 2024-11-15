#include <fstream>
#include <iostream>
#include <sstream>
#include <exception>
#include <ctime>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filepath) : _data_path("data.csv")
{
	std::ifstream	f_data(_data_path.c_str(), std::ios_base::in);

	if (!f_data.is_open())
	{
		throw std::invalid_argument("Can't find Data File");
		return ;
	}

	std::ifstream	f_input(filepath.c_str(), std::ios_base::in);

	if (!f_input.is_open())
	{
		throw std::invalid_argument("Can't Open Input File");
		return ;
	}
		
	validData(f_data);
	validInput(f_input);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::validInput(std::ifstream& input)
{
	std::string line;
	bool isFirstLine = true;

	while (std::getline(input, line))
	{
		std::stringstream ss(line);
		std::string date, rate;

		// 첫 번째 줄은 헤더로 확인만 하고 넘어감
		if (isFirstLine)
		{
			if (line != "date | value")
			{
				std::cout << "Error: bad input form\n";
				return ;
			}
			isFirstLine = false;
			continue;
		}

		if (!std::getline(ss, date, '|') || !std::getline(ss, rate))
		{
			std::cout << "Error: bad input => " << date << "\n"; continue;
		}
			// throw std::invalid_argument("Invalid Input format");

		// 날짜와 환율 유효성 확인
		if (date.size() != 11 || date[4] != '-' || date[7] != '-')
		{
			std::cout << "Error: bad input => " << date << "\n"; continue;
		}

		date.erase(10);
			// throw std::invalid_argument("Invalid Input format"); // 날짜 형식이 YYYY-MM-DD가 아닌 경우

		int year, month, day;
		char dash1, dash2;

		// 날짜를 분해하여 year, month, day에 저장
		std::istringstream iss(date);
		iss >> year >> dash1 >> month >> dash2 >> day;

		// 구분자가 '-'인지 확인
		if (dash1 != '-' || dash2 != '-')
		{
			std::cout << "Error: bad input => " << date << "\n"; continue;
		}
			// throw std::invalid_argument("Invalid Input format");

		if (!isValidDate(year, month, day))
		{
			std::cout << "Error: bad input => " << date << "\n"; continue;
		}

		if (!isValidExchangeRate(rate))
		{
			std::cout << "Error: bad input => " << rate << "\n"; continue;
		}

		// std::cout << "\tdate:" << date << "\n\tfoundDate: " << findData(date) << "\n";
		std::cout << date << " =>" << rate << " = " << strtod(rate.c_str(), NULL) * findData(date) << "\n";
	}
	if (isFirstLine)
		throw std::invalid_argument("Error: bad input form");

	return ;
}

double		BitcoinExchange::findData(std::string date)
{
	if (_data.find(date) != _data.end())
		return _data[date];
	
	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); ++it)
	{
		if (it != _data.begin() && it->first > date)
			return (--it)->second;
	}
	return (0);
}

int		BitcoinExchange::validData(std::ifstream& file)
{
	std::string line;
	bool isFirstLine = true;

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, rate;

		// 첫 번째 줄은 헤더로 확인만 하고 넘어감
		if (isFirstLine) {
			if (line != "date,exchange_rate") {
				std::cerr << "Invalid Data header format.\n";
				return 0;
			}
			isFirstLine = false;
			continue;
		}

		// CSV 형식으로 나누기
		if (!std::getline(ss, date, ',') || !std::getline(ss, rate))
			throw std::invalid_argument("Invalid CSV format");

		// 날짜와 환율 유효성 확인

			if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("Invalid CSV format"); // 날짜 형식이 YYYY-MM-DD가 아닌 경우

		int year, month, day;
		char dash1, dash2;

		// 날짜를 분해하여 year, month, day에 저장
		std::istringstream iss(date);
		iss >> year >> dash1 >> month >> dash2 >> day;

		// 구분자가 '-'인지 확인
		if (dash1 != '-' || dash2 != '-') 
			throw std::invalid_argument("Invalid CSV format");

		if (!isValidDate(year, month, day))
			throw std::invalid_argument("Invalid Date format");
		if (!isValidExchangeRate(rate))
			throw std::invalid_argument("Invalid Rate format");

		_data[date] = std::strtod(rate.c_str(), NULL);
	}

	return 1;
}

int BitcoinExchange::isValidDate(int year, int month, int day)
{
	if (year < 1 || month < 1 || month > 12 || day < 1)
		return (0);

	int max_date;
	if ((month < 8 && month % 2 == 1) || (month > 7 && month % 2 == 0))
		max_date = 31;
	else
	{
		if (month == 2)
			max_date = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
		else
			max_date = 30;
	}
	if (day > max_date)
		return (0);
	return (1);
}

int BitcoinExchange::isValidExchangeRate(const std::string& rate) {
	std::istringstream iss(rate);
	double value;
	char extra;

	// 문자열을 double로 변환하고, 변환 후 남은 문자가 있는지 확인
	if (!(iss >> value) || iss >> extra || value < 0 || value > std::numeric_limits<int>::max())
		return (0);

	// 소수점 자릿수 확인
	size_t dotPos = rate.find('.');
	if (dotPos != std::string::npos) 
		if (rate.size() - dotPos - 1 > 2)  // 소수점 뒤 자릿수가 2보다 큰 경우
			return (0);
	return (1);
}