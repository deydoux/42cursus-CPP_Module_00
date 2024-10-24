#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define PHONEBOOK_SIZE_MAX 8

#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact _contacts[PHONEBOOK_SIZE_MAX];
	size_t _oldestIndex;
	size_t _size;
public:
	PhoneBook();
	~PhoneBook();
	void add();
	void search();
};

#endif
