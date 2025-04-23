/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:04 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/23 10:40:31 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACH_H
# define CONTACH_H

#include <string>
#include <ctime>

class Contact {

	public:

		Contact(void);
		~Contact(void);

		void		setContact(std::string firstName, std::string lastName,	std::string nickName,
				std::string phoneNumber, std::string darkestSecret);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
		time_t		getCreationTime(void) const;

	private:

		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNumber;
		std::string		_darkestSecret;
		time_t			_creationTime;
};

#endif
