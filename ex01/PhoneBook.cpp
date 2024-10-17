#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _oldestIndex(0), _size(0) {
	std::cerr << "PhoneBook constructor called" << std::endl;
}

static std::string readField(const std::string fieldName) {
	if (std::cin.eof())
		return (std::string());

	while (true) {
		std::cout << fieldName << ": ";
		std::string content;
		std::getline(std::cin, content);

		if (std::cin.eof()) {
			std::cout << std::endl;
			return (std::string());
		}

		if (content.size())
			return (content);

		std::cout << "Empty field not allowed" << std::endl;
	}
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
		std::cout << "PhoneBook empty" << std::endl << std::endl;
		return ;
	}

	std::cout << "________________________________________________" << std::endl;
	std::cout << "| index | first name | last name  | nickname   |" << std::endl << std::endl;

	for (size_t i = 0; i < this->_size; i++)
		std::cout << "|   " << i << "   | " << std::setw(10) << truncate(this->_contacts[i].getFirstName()) << " | "
			<< std::setw(10) << truncate(this->_contacts[i].getLastName()) << " | " << std::setw(10) << truncate(this->_contacts[i].getNickname()) << " |"
			<< std::endl;

	std::cout << std::endl;

	size_t index;
	std::string input;
	std::stringstream input_s;
	do {
		if (!input_s.good())
			std::cout << "Invalid index" << std::endl;

		std::cout << "Index [0";
		if (this->_size > 1)
			std::cout << "-" << this->_size - 1;
		std::cout << "]: ";

		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return ;
		}

		input_s.clear();
		input_s.str(input);

		input_s >> index;
		if (input_s.bad())
			return ;
	} while (!input_s.eof() || index >= this->_size);

	std::cout << std::endl << this->_contacts[index] << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cerr << "PhoneBook destructor called" << std::endl;
}
