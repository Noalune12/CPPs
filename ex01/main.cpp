#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "PhoneBook.hpp"

void	print_contact(const Contact &Contact, int index)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;

	firstName = Contact.getFirstName();
	lastName = Contact.getLastName();
	nickName = Contact.getNickname();

	std::cout << std::setw(10) << std::right << index << " | ";
	if (firstName.length() > 10)
		firstName = firstName.substr(0, 9) + ".";
	if (lastName.length() > 10)
		lastName = lastName.substr(0, 9) + ".";
	if (nickName.length() > 10)
		nickName = nickName.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << firstName << " | ";
	std::cout << std::setw(10) << std::right << lastName << " | ";
	std::cout << std::setw(10) << std::right << nickName << std::endl;
}

void	print_all_contact(const PhoneBook &phonebook)
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


void	search_contact(const PhoneBook &phonebook)
{
	int index;
	int contact_found = 0;
	std::string input;

	index = phonebook.getIndex();
	if (index== 0)
	{
		std::cout << "No contacts available, please add one before searching" << std::endl;
		return ;
	}
	while (contact_found == 0 || input.length() == 0)
	{
		std::cout << "Which contact are you searching : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exiting program" << std::endl;
			exit(0);
		}
		if (input.length() == 0)
			std::cout << "Nothing was entered" << std::endl;
		else if (input.length() > 1 || !isdigit(input[0]))
			std::cout << "You should enter a number between 1 and " << phonebook.getIndex() << std::endl;
		else if (input.length() == 1)
		{
			index = input[0] - '0';
			if (index < 1 || index > phonebook.getIndex())
				std::cout << "You should enter a number between 1 and " << phonebook.getIndex() << std::endl;
			else
				contact_found = 1;
		}
	}
	print_contact(phonebook.contacts[index - 1], index);
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
	// int	index;

	while (1)
	{
		// index = phonebook.getIndex();
		// std::cout << "Index: " << index << std::endl;
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, arg); // read entire line including spaces + automtically empty buffer
		if (arg == "EXIT" || std::cin.eof())
			break ;
		else if (arg == "ADD")
			add_contact(&phonebook);
		else if (arg == "SEARCH")
			search_contact(phonebook);
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
