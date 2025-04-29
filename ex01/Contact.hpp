/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:16:04 by lbuisson          #+#    #+#             */
/*   Updated: 2025/04/29 12:58:24 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACH_H
# define CONTACH_H

#include <string>

class Contact {

	public:

		Contact(void);
		~Contact(void);

		bool	setContact();
		void	printTable(int index) const;
		void	printOne(int index) const;

	private:

		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNumber;
		std::string		_darkestSecret;
};

#endif
