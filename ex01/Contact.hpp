#ifndef CONTACH_HPP
# define CONTACH_HPP

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
