#include <iostream>
#include <ctime>
#include <string>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< "index:" <<  this->_accountIndex
				<< ";amount:" << this->checkAmount()
				<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:" <<  this->_accountIndex
				<< ";amount:" << this->checkAmount()
				<< ";closed" << std::endl;
	this->_nbAccounts--;
	this->_totalAmount -= this->checkAmount();
}

int		Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int		Account::getTotalAmount(void)
{
	return _totalAmount;
}

int		Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	if (deposit < 0)
		std::cerr << "!!Wrong amount deposit!!" << std::endl;

	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->checkAmount()
				<< ";deposit:" << deposit
				<< ";amount:" << this->checkAmount() + deposit
				<< ";nb_deposits:" << ++this->_nbDeposits
				<< std::endl;

	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal < 0 || withdrawal > this->checkAmount())
	{
		_displayTimestamp();
		std::cout	<< "index:" << this->_accountIndex
					<< ";p_amount:" << this->checkAmount()
					<< ";withdrawal:refused"
					<< std::endl;
		return (false);
	}

	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->checkAmount()
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << this->checkAmount() - withdrawal
				<< ";nb_withdrawals:" << ++this->_nbWithdrawals
				<< std::endl;

	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	return (true);
}

int		Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->checkAmount()
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

/* private */

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltm);

	std::cout << buffer;
}