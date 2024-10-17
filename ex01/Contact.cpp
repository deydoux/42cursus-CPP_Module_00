#include "Contact.hpp"

Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber,
	const std::string &darkestSecret)
	: _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {
	std::cerr << this->_firstName << " " << this->_lastName << " Contact constructor called" << std::endl;
}

Contact &Contact::operator=(const Contact &rhs) {
	std::cerr << this->_firstName << " " << this->_lastName << " Contact copy operator called" << std::endl;
	this->_firstName = rhs._firstName;
	this->_lastName = rhs._lastName;
	this->_nickname = rhs._nickname;
	this->_phoneNumber = rhs._phoneNumber;
	this->_darkestSecret = rhs._darkestSecret;
	return (*this);
}

std::string Contact::getFirstName()
{
	return (this->_firstName);
}

std::string Contact::getLastName()
{
	return (this->_lastName);
}

std::string Contact::getNickname()
{
	return (this->_nickname);
}

Contact::~Contact() {
	std::cerr << this->_firstName << " " << this->_lastName << " Contact destructor called" << std::endl;
}
