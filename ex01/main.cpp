/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:10 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/28 16:53:17 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>

#include "PhoneBook.hpp"

int	main(void) {
	std::string	arg;
	PhoneBook	phoneBook;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, arg);
		if (arg == "EXIT" || std::cin.eof())
			break ;
		else if (arg == "ADD")
		{
			if (phoneBook.addContact() == false)
				break ;
		}
		else if (arg == "SEARCH")
		{
			if (phoneBook.searchContact() == false)
				break ;
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
