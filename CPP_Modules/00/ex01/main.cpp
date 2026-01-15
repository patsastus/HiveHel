#include <iostream>
#include <string>
#include <limits>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void searchBook(PhoneBook &pb)
{
	std::cout << "Listing PhoneBook contents:" << std::endl;
	std::cout << pb <<std::endl;
	int input = -1;
	while (input == -1){
		std::cout << "Type index of contact entry to print, or 8 to exit" << std::endl;
		std::cin >> input;
		if (std::cin.fail())
			std::cin.clear();
		else if (input >= 0 && input <= 8)
			break;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "please provide a number between 0 and 8" << std::endl;
			input = -1;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (input == 8)
		return ;
	if (input >= pb.getSize())
		std::cout << "No entry with index " << input << std::endl;
	else
		std::cout << pb.getContact(input) << std::endl;
}

void takeEntry(PhoneBook &pb)
{
	std::string prompts[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	std::string data[5];
	std::string input = "";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < 5; ++i){
		std::cout << "Please provide a " << prompts[i] << " for contact:" << std::endl;
		std::getline(std::cin, input);
		if(input.length() == 0){
			--i;
			continue;
		}
		data[i] = input;
		input = "";
	}
	pb.addContact(data);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	PhoneBook book;
	const std::string	commands[3] =  {"ADD", "SEARCH", "EXIT"};
	while (true){
		std::string input;
		std::cout << "Choose action: ADD, SEARCH or EXIT" << std::endl;
		std::cin >> input;
		if (input.empty())
			continue ;
		else if(input == (commands[0]))
			takeEntry(book);
		else if (input == (commands[1]))
			searchBook(book);
		else if (input == (commands[2]))
			break ;
		input = "";
	}
	return (0);
}
