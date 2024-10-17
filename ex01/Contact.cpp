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

std::string Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string Contact::getLastName() const
{
	return (this->_lastName);
}

std::string Contact::getNickname() const
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

Contact::~Contact() {
	std::cerr << this->_firstName << " " << this->_lastName << " Contact destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Contact &contact)
{
	std::cerr << contact.getFirstName() << " " << contact.getLastName() << " Contact overload operator called" << std::endl;
	o << "First name: " << contact.getFirstName() << std::endl << "Last name: " << contact.getLastName() << std::endl
		<< "Nickname: " << contact.getNickname() << std::endl << "Phone number: " << contact.getPhoneNumber() << std::endl
		<< "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	return (o);
}
