/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:51:24 by yeondcho          #+#    #+#             */
/*   Updated: 2024/07/26 13:25:12 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_index;

	public:
		PhoneBook();
		~PhoneBook();
		std::string	print_inline(std::string str) const;
		void		display() const;
		void		search() const;
		int			add();
};

#endif