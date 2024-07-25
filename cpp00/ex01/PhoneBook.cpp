/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:51:10 by yeondcho          #+#    #+#             */
/*   Updated: 2024/07/11 13:30:36 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add()
{
	std::string	info[5];

	std::cout << "FirstName> ";
	std::cin >> info[0];
	std::cout << "LastName> ";
	std::cin >> info[1];
	std::cout << "NickName> ";
	std::cin >> info[2];
	std::cout << "PhoneNumber >";
	std::cin >> info[3];
	std::cout << "Secret> ";
	std::cin >> info[4];

	this->_contacts[this->_index].setInfo(info[0], info[1], info[2], info[3], info[4]);
	this->_index = (this->_index + 1) % 8;
}

void	PhoneBook::display() const
{
	std::cout << "Index" << "|" << std::setw(10) << "Firstname" << "|" << std::setw(10) << "Lastname" << "|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; ++i)
	{
		Contact curContact = this->_contacts[i];
		if (curContact.getInfo(FIRST).length() != 0)
			std::cout << std::setw(5) << i << "|" << std::setw(10) << curContact.getInfo(FIRST) << "|" << std::setw(10) << curContact.getInfo(LAST) << "|" << std::setw(10) << curContact.getInfo(NICK) << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::search() const
{
	int	index;

	std::cout << "Choose Contact Index" << std::endl << "Index> ";
	std::cin >> index;
	if (index < 0 || index > 7)
	{
		std::cout << "Wrong Index" << std::endl;
		return;
	}
	if (this->_contacts->getInfo(FIRST).length() == 0)
	{
		std::cout << "Empty Contact" << std::endl;
		return;
	}
	
	std::string field[5] = {"FirstName", "LastName", "NickName", "PhoneNumber", "Secret"};

	std::cout << "[ No." << index << " Contact Information ]" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << std::setw(12) <<  field[i] << " : " << std::setw(20) << this->_contacts[index].getInfo(InfoType(i)) << std::endl;
	}
}
