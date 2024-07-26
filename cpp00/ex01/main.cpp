/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:30:37 by yeondcho          #+#    #+#             */
/*   Updated: 2024/07/25 22:37:17 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::string	cmd;

	while (1)
	{
		std::cout << "PhoneBook> " << std::flush;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		if (cmd.compare("ADD") == 0 && !book.add())
			break;
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