#include <iostream>

#include "Contact.hpp"

int	main(void)
{
	Contact contact;
	Contact contact2;
	int	id = 0;

	std::cout << "This will be a phonebook" << std::endl;
	contact.setId(&id);
	std::cout << "Contact id: " << contact.id << std::endl;
	contact2.setId(&id);
	std::cout << "Contact2 id: " << contact2.id << std::endl;
	return 0;
}
