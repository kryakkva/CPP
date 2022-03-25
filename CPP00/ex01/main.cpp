#include "PhoneBook.hpp"

int main ()
{
	PhoneBook phoneBook;
	std::string cmd;

	std::cout << "That's crappy awesome phonebook\n";
	while (true)
	{
		std::cout << "Please enter one of the commands: ADD, SEARCH, EXIT\n";
		std::cout << ">";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phoneBook.addContact();
		else if (cmd == "SEARCH")
			phoneBook.searchContact();
		else if (cmd == "EXIT") {
			break ;
		}
	}
	return(0);
}
