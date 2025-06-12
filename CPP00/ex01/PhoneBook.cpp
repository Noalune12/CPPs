/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:18:16 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/29 10:35:25 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "PhoneBook constructor called" << std::endl;
	_index = 0;
	_maxIndex = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook destructor called" << std::endl;
	return;
}

bool PhoneBook::addContact() {
	if (_index == MAX_CONTACTS)
		_index = 0;
	if (_contacts[_index].setContact() == false)
		return (false);
	_index++;
	if (_maxIndex < MAX_CONTACTS)
		_maxIndex++;
	return (true);
}

bool PhoneBook::searchContact() const {
	std::string	input;
	int			i;

	if (_index == 0)
	{
		std::cout << "No contacts available, please add one before searching" << std::endl;
		return (true);
	}
	for (int i = 0; i < _maxIndex; i++)
		_contacts[i].printTable(i);
	std::cout << std::endl;
	while (1) {
		std::cout << "Which contact are you searching : " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (false);
		if (input.length() == 0)
			std::cout << "Nothing was entered" << std::endl;
		else if (input.length() > 1 || !isdigit(input[0]))
			std::cout << "You should enter a number between 1 and " << _maxIndex << std::endl;
		else if (input.length() == 1)
		{
			i = input[0] - '0';
			if (i < 1 || i > _maxIndex)
				std::cout << "You should enter a number between 1 and " << _maxIndex << std::endl;
			else {
				_contacts[i - 1].printOne(i);
				break ;
			}
		}
	}
	return (true);
}
