#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {

	public:

		Contact	contacts[8];
		PhoneBook(void);
		~PhoneBook(void);

		int	getIndex(void) const; // will never modify the instance

	private:

		int		_index;
};

#endif
