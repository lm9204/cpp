/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:05:01 by yeondcho          #+#    #+#             */
/*   Updated: 2024/07/11 13:02:18 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

enum InfoType
{
	FIRST,
	LAST,
	NICK,
	PHONE,
	SECRET,
};

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact();
		Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
		~Contact();
		std::string getInfo(InfoType type) const;
		void setInfo(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
};

#endif