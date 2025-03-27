#include <iostream>
#include <cstdlib>

#include "PhoneBook.hpp"

void	print_contact(const PhoneBook &phonebook)
{
	for (int i = 0; i < phonebook.getIndex() ; i++)
	{
		std::cout << "         " << i + 1 << "    |    ";
		std::cout << phonebook.contacts[i].getFirstName() << "    |    ";
		std::cout << phonebook.contacts[i].getLastName() << "    |    ";
		std::cout << phonebook.contacts[i].getNickname() <<  "    |    ";
		std::cout << phonebook.contacts[i].getPhoneNumber() <<  "    |    ";
		std::cout << phonebook.contacts[i].getDarkestSecret() << "    |    ";
		std::cout << phonebook.contacts[i].getCreationTime() << std::endl;
	}
}

std::string	get_user_info(std::string str)
{
	std::string	user_info;

	std::cout << "Enter your " << str << ": ";
	std::getline(std::cin, user_info);
	if (std::cin.eof())
	{
		std::cout << "Exiting program" << std::endl;
		exit(0);
	}
	while (user_info.length() == 0)
	{
		std::cout << "Nothing was entered" << std::endl;
		std::cout << "Enter your " << str << ": ";
		std::getline(std::cin, user_info);
		if (std::cin.eof())
		{
			std::cout << "Exiting program" << std::endl;
			exit(0);
		}
	}
	return (user_info);
}

void	add_contact(PhoneBook *phonebook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	firstName = get_user_info("first name");
	lastName = get_user_info("last name");
	nickName = get_user_info("nick name");
	phoneNumber = get_user_info("phone number");
	darkestSecret = get_user_info("darkest secret");
	phonebook->AddContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

int	main(void)
{
	std::string	arg;
	PhoneBook	phonebook;
	int	index;

	while (1)
	{
		// index = phonebook.getIndex();
		// std::cout << "Index: " << index << std::endl;
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, arg); // read entire line including spaces + automtically empty buffer
		if (arg == "EXIT" || std::cin.eof())
			break ;
		else if (arg == "ADD")
		{
			add_contact(&phonebook);
			print_contact(phonebook);
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}

// int	main(void)
// {
// 	Contact contact;
// 	Contact contact2;
// 	std::string firstName = "Lou";
// 	std::string lastName = "BUISSON";
// 	std::string firstName2 = "Elvis";
// 	std::string lastName2 = "Presley";
// 	int	id = 0;

// 	std::cout << "This will be a phonebook" << std::endl;
// 	contact.setContact(&id, firstName, lastName);
// 	std::cout << "Contact id: " << contact.id << std::endl;
// 	std::cout << "Contact first name: " << contact.firstName << std::endl;
// 	std::cout << "Contact last name: " << contact.lastName << std::endl;
// 	contact2.setContact(&id, firstName2, lastName2);
// 	std::cout << "Contact2 id: " << contact2.id << std::endl;
// 	std::cout << "Contact2 first name: " << contact2.firstName << std::endl;
// 	std::cout << "Contact2 last name: " << contact2.lastName << std::endl;
// 	return 0;
// }
