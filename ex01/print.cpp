/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:19:05 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/23 09:28:53 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <cstdlib>
#include <iostream>

#include "PhoneBook.hpp"

void	print_contact(const Contact &Contact, int index) {
	std::string	firstName = Contact.getFirstName();
	std::string	lastName = Contact.getLastName();
	std::string	nickName = Contact.getNickname();

	std::cout << " ___________________________________________________" << std::endl;
	std::cout << "| "<< std::setw(10) << std::right << index << " | ";
	if (firstName.length() > 10)
		firstName = firstName.substr(0, 9) + ".";
	if (lastName.length() > 10)
		lastName = lastName.substr(0, 9) + ".";
	if (nickName.length() > 10)
		nickName = nickName.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << firstName << " | ";
	std::cout << std::setw(10) << std::right << lastName << " | ";
	std::cout << std::setw(10) << std::right << nickName << " |" << std::endl;
}

void	print_all_contact(const PhoneBook &phonebook) {
	for (int i = 0; i < phonebook.getIndex() ; i++)
		print_contact(phonebook.contacts[i], i + 1);
}

void	get_contact_index(const PhoneBook &phonebook, int *index) {
	int contact_found = 0;
	std::string input;

	while (contact_found == 0 || input.length() == 0)
	{
		std::cout << "Which contact are you searching : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Exiting program" << std::endl;
			exit(0);
		}
		if (input.length() == 0)
			std::cout << "Nothing was entered" << std::endl;
		else if (input.length() > 1 || !isdigit(input[0]))
			std::cout << "You should enter a number between 1 and " << phonebook.getIndex() << std::endl;
		else if (input.length() == 1)
		{
			*index = input[0] - '0';
			if (*index < 1 || *index > phonebook.getIndex())
				std::cout << "You should enter a number between 1 and " << phonebook.getIndex() << std::endl;
			else
				contact_found = 1;
		}
	}
}

void	search_contact(const PhoneBook &phonebook) {
	int index = phonebook.getIndex();

	if (index== 0)
	{
		std::cout << "No contacts available, please add one before searching" << std::endl;
		return ;
	}
	print_all_contact(phonebook);
	std::cout << std::endl;
	get_contact_index(phonebook, &index);
	print_contact(phonebook.contacts[index - 1], index);
	std::cout << std::endl;
}
