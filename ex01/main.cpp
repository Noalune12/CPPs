#include <iostream>

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	int	index;

	index = phonebook.getIndex();
	std::cout << "Index: " << index << std::endl;
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
