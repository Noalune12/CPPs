/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:18:39 by lbuisson          #+#    #+#             */
/*   Updated: 2025/03/31 15:18:40 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {

	public:

		Contact	contacts[MAX_CONTACTS];
		PhoneBook(void);
		~PhoneBook(void);

		void		AddContact(std::string firstName, std::string lastName,	std::string nickName,
			std::string phoneNumber, std::string darkestSecret);
		int	getIndex(void) const;

	private:

		int		_index;
};

void	search_contact(const PhoneBook &phonebook);

#endif
