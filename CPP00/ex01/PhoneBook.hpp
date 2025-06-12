/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:18:39 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/29 13:26:24 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {

	public:

		PhoneBook(void);
		~PhoneBook(void);

		bool	addContact();
		bool	searchContact() const;

	private:

		Contact	_contacts[MAX_CONTACTS];
		int		_index;
		int		_maxIndex;
};


#endif
