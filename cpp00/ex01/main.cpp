/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:30:37 by yeondcho          #+#    #+#             */
/*   Updated: 2024/07/25 12:05:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::string	cmd;

	while (1)
	{
		std::cout << "PhoneBook> ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		if (cmd.compare("ADD") == 0)
			book.add();
		else if (cmd.compare("SEARCH") == 0)
		{
			book.display();
			book.search();
		}
		else if (cmd.compare("EXIT") == 0)
			break;
	}
	return (0);
}