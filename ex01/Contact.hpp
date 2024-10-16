#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
public:
	Contact(const std::string &firstName = "Undefined first name", const std::string &lastName = "Undefined last name",
		const std::string &nickname = "Undefined nickname", const std::string &phoneNumber = "Undefined phone number",
		const std::string &darkestSecret = "Undefined darkest secret");
	Contact &operator=(const Contact &rhs);
	~Contact();
};

#endif
