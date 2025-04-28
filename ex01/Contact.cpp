/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:00 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/28 17:23:26 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
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
	int	count = 0;

	while (count != 5) {
		if (count == 0) {
			std::cout << "Enter your first name : " << std::flush;
			std::getline(std::cin, _firstName);
			if (_firstName.empty())
				std::cout << "Nothing was entered" << std::endl;
			else
				count++;
		}
		else if (count == 1) {
			std::cout << "Enter your last name : " << std::flush;
			std::getline(std::cin, _lastName);
			if (_lastName.empty())
				std::cout << "Nothing was entered" << std::endl;
			else
				count++;
		}
		else if (count == 2) {
			std::cout << "Enter your nickname : " << std::flush;
			std::getline(std::cin, _nickName);
			if (_nickName.empty())
				std::cout << "Nothing was entered" << std::endl;
			else
				count++;
		}
		else if (count == 3) {
			std::cout << "Enter your phone number : " << std::flush;
			std::getline(std::cin, _phoneNumber);
			if (_phoneNumber.empty())
				std::cout << "Nothing was entered" << std::endl;
			else
				count++;
		}
		else if (count == 4) {
			std::cout << "Enter your darkest secret : " << std::flush;
			std::getline(std::cin, _darkestSecret);
			if (_darkestSecret.empty())
				std::cout << "Nothing was entered" << std::endl;
			else
				count++;
		}
		if (std::cin.eof())
			return (false);
	}
	return (true);
}

void Contact::printAll(int index) {
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

void Contact::printOne(int index) {
	std::cout << "Contact " << index << std::endl;
	std::cout << "First Name : " << _firstName << std::endl;
	std::cout << "Last Name : " << _lastName << std::endl;
	std::cout << "Nickname  : " << _nickName << std::endl;
	std::cout << "Phone Number : " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret : " << _darkestSecret << std::endl;
}

