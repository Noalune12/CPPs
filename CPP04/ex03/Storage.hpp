/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Storage.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:33:43 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:33:45 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORAGE_H
#define STORAGE_H

class AMateria;

class Storage {

	public:
		Storage();
		Storage(Storage const& src);
		~Storage();

		Storage& operator=(Storage const& src);

		void addStorage(AMateria* m);
		void compareStorage(AMateria* m);

	private:
		AMateria **_storage;
		int _capacity;
		int _size;
};

#endif
