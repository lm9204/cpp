/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:51:10 by yeondcho          #+#    #+#             */
/*   Updated: 2024/07/26 10:47:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0) {}

PhoneBook::~PhoneBook() {}

int	PhoneBook::add()
{
	std::string	info[5];
	std::string	prompt_msg[5] = 
		{"FirstName> ",
		"LastName> ",
		"NickName> ",
		"PhoneNumber> ",
		"Secret> ",
		};
	std::string	msg;

	for (int i = 0; i < 5; ++i)
	{
		std::cout << prompt_msg[i];
		std::getline(std::cin, msg);
		if (std::cin.eof())
			return (1);
		if (msg.length() == 0)
		{
			i--;
			continue;
		}
		for (size_t j = 0; j < msg.length(); ++j)
		{
			if (!std::isprint(msg[j]))
			{
				std::cout << "Wrong Input" << std::endl;
				return (1);
			}
		}
		
		info[i] = msg;
	}
	
	for (int i = this->_index; i >= 0; --i)
	{
		if (i > 6)
			continue;
		this->_contacts[i + 1] = this->_contacts[i];
	}
	this->_contacts[0].setInfo(info[0], info[1], info[2], info[3], info[4]);
	if (this->_index < 8)
		this->_index++;
	std::cout << "Contact is Successfully done" << std::endl;
	return (1);
}

void	PhoneBook::display() const
{
	if (this->_index == 0)
	{
		std::cout << "No Contacts" << std::endl;
		return ;
	}

	std::cout
	<< std::setw(10) << "Index" << "|"
	<< std::setw(10) << "Firstname" << "|"
	<< std::setw(10) << "Lastname" << "|"
	<< std::setw(10) << "Nickname"
	<< std::endl;
	for (int i = 0; i < 8; ++i)
	{
		Contact curContact = this->_contacts[i];
		if (curContact.getInfo(FIRST).length() != 0)
			std::cout
			<< std::setw(10) << i + 1 << "|"
			<< std::setw(10) << print_inline(curContact.getInfo(FIRST)) << "|"
			<< std::setw(10) << print_inline(curContact.getInfo(LAST)) << "|"
			<< std::setw(10) << print_inline(curContact.getInfo(NICK))
			<< std::endl;
	}
	std::cout << std::endl;
}

std::string	PhoneBook::print_inline(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9).append(".");
	else
		return str;
}

void	PhoneBook::search() const
{
	int index;

	if (this->_index == 0)
		return;
	std::cout << "Choose Contact Index" << std::endl;
	while (true)
	{
		index = -1;

		std::cout << "Index> " << std::flush;
		std::cin >> index;
		if (std::cin.eof())
			return ;
		if (std::cin.fail())
		{
			std::cout << "Wrong Index" << std::endl;
			std::cin.clear();
			// std::cin.ignore(std::numeric_limits<std::streamsize>::std::max(), '\n');
		}
		else if (0 < index && index <= this->_index)
			break;
		else
		{
			std::cout << "Wrong Index" << std::endl;
			// std::cin.ignore(std::numeric_limits<std::streamsize>::std::max(), '\n');
		}
	}
	std::string field[5] = {"FirstName", "LastName", "NickName", "PhoneNumber", "Secret"};

	std::cout << "[ No." << index << " Contact Information ]" << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout
		<<  field[i] << " : "
		<< this->_contacts[index - 1].getInfo(InfoType(i))
		<< std::endl;
	// std::cin.ignore(std::numeric_limits<std::streamsize>::std::max(), '\n');
}
