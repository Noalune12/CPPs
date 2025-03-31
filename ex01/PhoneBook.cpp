/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:18:16 by lbuisson          #+#    #+#             */
/*   Updated: 2025/03/31 15:18:17 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook constructor called" << std::endl;
	_index = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook destructor called" << std::endl;
	return;
}

int	PhoneBook::getIndex(void) const {
	return (_index);
}

int	find_oldest_contact(PhoneBook *phonebook)
{
	time_t	oldest_time = phonebook->contacts[0].getCreationTime();
	int	oldest_index = 0;

	for (int i = 1; i < phonebook->getIndex(); i++)
	{
		if (phonebook->contacts[i].getCreationTime() < oldest_time)
		{
			oldest_time = phonebook->contacts[i].getCreationTime();
			oldest_index = i;
		}
	}
	return (oldest_index);
}


void	PhoneBook::AddContact(std::string firstName, std::string lastName, std::string nickName,
	std::string phoneNumber, std::string darkestSecret) {
	int	oldest_index;

	if (_index < MAX_CONTACTS)
	{
		contacts[_index].setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
		_index++;
	}
	else
	{
		oldest_index = find_oldest_contact(this);
		contacts[oldest_index].setContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	}
	return;
}
