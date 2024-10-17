#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _oldestIndex(0), _size(0) {
	std::cerr << "PhoneBook constructor called" << std::endl;
}

static std::string readField(const std::string fieldName) {
	if (std::cin.eof())
		return (std::string());

	std::cout << fieldName << ": ";
	std::string content;
	std::getline(std::cin, content);

	if (std::cin.eof())
		std::cout << std::endl;

	return content;
}

void PhoneBook::add() {
	std::cout << std::endl;
	this->_contacts[this->_oldestIndex] = Contact(readField("First name"), readField("Last name"), readField("Nickname"), readField("Phone number"),
		readField("Darkest secret"));
	std::cout << std::endl;

	++this->_oldestIndex %= PHONEBOOK_SIZE_MAX;
	if (this->_size < PHONEBOOK_SIZE_MAX)
		this->_size++;
}

static std::string truncate(std::string str)
{
	if (str.size() > 10)
		str[9] = '.';
	return (str);
}

void PhoneBook::search() {
	if (!this->_size)
	{
		std::cout << "PhoneBook empty" << std::endl;
		return ;
	}

	std::cout << "________________________________________________" << std::endl;
	std::cout << "| index | first name | last name  | nickname   |" << std::endl << std::endl;

	for (size_t i = 0; i < this->_size; i++)
		std::cout << "|   " << i << "   | " << std::setw(10) << truncate(this->_contacts[i].getFirstName()) << " | "
			<< std::setw(10) << truncate(this->_contacts[i].getLastName()) << " | " << std::setw(10) << truncate(this->_contacts[i].getNickname()) << " |"
			<< std::endl;

	std::cout << std::endl;

	std::string input;
	do {
		if (input.size())
			std::cout << "Invalid \"" << input << "\" index" << std::endl;

		if (this->_size > 1)
			std::cout << "Index [0-" << this->_size - 1 << "] ";
		else
			std::cout << "Index [0] ";
		std::getline(std::cin, input);

		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
	} while (input.size() != 1 || !std::isdigit(input[0]) || (size_t)input[0] - '0' >= this->_size);

	std::cout << std::endl << this->_contacts[input[0] - '0'] << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cerr << "PhoneBook destructor called" << std::endl;
}
