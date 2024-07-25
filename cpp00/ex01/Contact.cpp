#include "Contact.hpp"

Contact::Contact()
	: _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("") {}

Contact::Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
	: _firstName(first), _lastName(last), _nickName(nick), _phoneNumber(phone), _darkestSecret(secret)
{
}

Contact::~Contact() {}

void	Contact::setInfo(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	this->_firstName = first;
	this->_lastName = last;
	this->_nickName = nick;
	this->_phoneNumber = phone;
	this->_darkestSecret = secret;
}

std::string Contact::getInfo(InfoType type) const
{
	switch (type)
	{
		case FIRST:
			return _firstName;
		case LAST:
			return _lastName;
		case NICK:
			return _nickName;
		case PHONE:
			return _phoneNumber;
		case SECRET:
			return _darkestSecret;
		default:
			return "";
	}
}
