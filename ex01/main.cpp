#include "PhoneBook.hpp"

int main() {
	PhoneBook	phoneBook;
	std::string	command;

	while (!std::cin.eof()) {
		std::cout << "[ADD/SEARCH/EXIT]: ";
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return (1);
		}
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else if (command == "EXIT")
			return (0);
		else
			std::cout << "Unrecognized \"" << command << "\" command" << std::endl;
	}

	return (std::cin.eof());
}
