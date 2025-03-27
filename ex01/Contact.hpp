#ifndef CONTACH_H
# define CONTACH_H

#include <iostream>

class Contact {

	public:

		Contact(void);
		~Contact(void);

		int	id;
		std::string	firstName;
		std::string	lastName;

		void	setContact(int *id, std::string firstName, std::string lastName);
};

#endif
