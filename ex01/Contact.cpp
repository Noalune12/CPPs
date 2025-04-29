/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:00 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/29 10:33:31 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Contact desctructor called" << std::endl;
	return;
}

bool Contact::setContact() {
	int				count = 0;
	std::string		inputs[5] = { "first name", "last name", "nickname", "phone number", "darkest secret" };
	std::string*	fields[5] = { &_firstName, &_lastName, &_nickName, &_phoneNumber, &_darkestSecret };

	while (count != 5) {
		std::cout << "Enter your " << inputs[count] << " : " << std::flush;
		std::getline(std::cin, *fields[count]);
		if (fields[count]->empty())
			std::cout << "Nothing was entered" << std::endl;
		else
			count++;
		if (std::cin.eof())
			return (false);
	}
	return (true);
}

void Contact::printTable(int index) const {
	std::cout << " ___________________________________________________" << std::endl;
	std::cout << "| "<< std::setw(10) << std::right << index + 1 << " | ";
	if (_firstName.length() > 10)
		std::cout << std::setw(10) << std::right << _firstName.substr(0, 9) + "." << " | ";
	else
		std::cout << std::setw(10) << std::right << _firstName << " | ";
	if (_lastName.length() > 10)
		std::cout << std::setw(10) << std::right << _lastName.substr(0, 9) + "." << " | ";
	else
		std::cout << std::setw(10) << std::right << _lastName << " | ";
	if (_nickName.length() > 10)
		std::cout << std::setw(10) << std::right << _nickName.substr(0, 9) + "." << " | " << std::endl;
	else
		std::cout << std::setw(10) << std::right << _nickName << " | " << std::endl;
}

void Contact::printOne(int index) const {
	std::cout << "Contact " << index << std::endl;
	std::cout << "First Name : " << _firstName << std::endl;
	std::cout << "Last Name : " << _lastName << std::endl;
	std::cout << "Nickname  : " << _nickName << std::endl;
	std::cout << "Phone Number : " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret : " << _darkestSecret << std::endl;
}

