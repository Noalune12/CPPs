/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:10 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/23 09:27:30 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>

#include "PhoneBook.hpp"

std::string	get_user_info(std::string str) {
	std::string	user_info;

	std::cout << "Enter your " << str << ": ";
	std::getline(std::cin, user_info);
	if (std::cin.eof())
	{
		std::cout << "Exiting program" << std::endl;
		exit(0);
	}
	while (user_info.length() == 0)
	{
		std::cout << "Nothing was entered" << std::endl;
		std::cout << "Enter your " << str << ": ";
		std::getline(std::cin, user_info);
		if (std::cin.eof())
		{
			std::cout << "Exiting program" << std::endl;
			exit(0);
		}
	}
	return (user_info);
}

void	add_contact(PhoneBook *phonebook) {
	std::string	firstName = get_user_info("first name");
	std::string	lastName = get_user_info("last name");
	std::string	nickName = get_user_info("nick name");
	std::string	phoneNumber = get_user_info("phone number");
	std::string	darkestSecret = get_user_info("darkest secret");

	phonebook->AddContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

int	main(void) {
	std::string	arg;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, arg);
		if (arg == "EXIT" || std::cin.eof())
			break ;
		else if (arg == "ADD")
			add_contact(&phonebook);
		else if (arg == "SEARCH")
			search_contact(phonebook);
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
