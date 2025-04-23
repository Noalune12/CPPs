/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:00 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/23 09:28:35 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Contact desctructor called" << std::endl;
	return;
}

void	Contact::setContact(std::string firstName, std::string lastName,	std::string nickName,
	std::string phoneNumber, std::string darkestSecret) {
	_firstName = firstName;
	_lastName = lastName;
	_nickName = nickName;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
	_creationTime = time(0);
	return;
}

std::string	Contact::getFirstName(void) const {
	return (_firstName);
}

std::string	Contact::getLastName(void) const {
	return (_lastName);
}

std::string	Contact::getNickname(void) const {
	return (_nickName);
}

std::string	Contact::getPhoneNumber(void) const {
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const {
	return (_darkestSecret);
}

time_t Contact::getCreationTime(void) const {
	return (_creationTime);
}
