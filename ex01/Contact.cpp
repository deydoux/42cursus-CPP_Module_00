#include "Contact.hpp"

Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber,
	const std::string &darkestSecret)
	: _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {
	std::cerr << _firstName << " " << _lastName << " Contact constructor called" << std::endl;
}

Contact::~Contact() {
	std::cerr << _firstName << " " << _lastName << " Contact destructor called" << std::endl;
}

Contact &Contact::operator=(const Contact &rhs) {
	std::cerr << _firstName << " " << _lastName << " Contact copy operator called" << std::endl;
	_firstName = rhs._firstName;
	_lastName = rhs._lastName;
	_nickname = rhs._nickname;
	_phoneNumber = rhs._phoneNumber;
	_darkestSecret = rhs._darkestSecret;
	return (*this);
}

std::string Contact::getFirstName() const {
	return (_firstName);
}

std::string Contact::getLastName() const {
	return (_lastName);
}

std::string Contact::getNickname() const {
	return (_nickname);
}

std::string Contact::getPhoneNumber() const {
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const {
	return (_darkestSecret);
}

std::ostream &operator<<(std::ostream &os, const Contact &contact) {
	os << "First name: " << contact.getFirstName() << std::endl
		<< "Last name: " << contact.getLastName() << std::endl
		<< "Nickname: " << contact.getNickname() << std::endl
		<< "Phone number: " << contact.getPhoneNumber() << std::endl
		<< "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	return (os);
}
