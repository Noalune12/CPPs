/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:32:01 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:32:09 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <string>

class Brain {

	public:
		Brain();
		Brain(Brain const& src);
		~Brain();

		Brain& operator=(Brain const& name);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string add);

	private:
		std::string ideas[100];
};

#endif
