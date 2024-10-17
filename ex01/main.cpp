#define USAGE "[ADD/SEARCH/EXIT]: "

#include "PhoneBook.hpp"
#include <cstdlib>

int main() {
	PhoneBook	phoneBook;
	std::string	command;

	while (!std::cin.eof()) {
		std::cout << USAGE;
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (EXIT_FAILURE);
		}
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			return (EXIT_SUCCESS);
		else
			std::cout << "Unrecognized \"" << command << "\" command" << std::endl;
	}

	return (std::cin.eof());
}
