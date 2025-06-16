/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Storage.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:33:40 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:33:42 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Storage.hpp"
#include "AMateria.hpp"

#include <iostream>

Storage::Storage(): _capacity(10), _size(0) {
	_storage = new AMateria*[_capacity];
	// std::cout << "Storage constructor called" << std::endl;
}

Storage::Storage(Storage const& src): _capacity(src._capacity), _size(src._size) {
	_storage = new AMateria*[_capacity];
	for (int i = 0; i < _size; i++)
	{
		if (src._storage[i])
			_storage[i] = src._storage[i]->clone();
		else
			_storage[i] = NULL;
	}
	// std::cout << "Storage copy constructor called" << std::endl;
}

Storage::~Storage() {
	for (int i = 0; i < _size; i++) {
		delete _storage[i];
	}
	delete[] _storage;
	// std::cout << "Storage destructor called" << std::endl;
}

Storage& Storage::operator=(Storage const& src) {
	if (this != &src) {
		for (int i = 0; i < _size; i++) {
			delete _storage[i];
		}
		delete[] _storage;
		_capacity = src._capacity;
		_size = src._size;
		_storage = new AMateria*[_capacity];
		for (int i = 0; i < _size; i++) {
			if (src._storage[i])
				_storage[i] = src._storage[i]->clone();
			else
				_storage[i] = NULL;
		}
	}
	// std::cout << "Storage operator called" << std::endl;
	return *this;
}

void Storage::addStorage(AMateria* m) {
	if (m == NULL)
		return;
	if (_size == _capacity) {
		std::cout << "Storage is resized" << std::endl;
		_capacity *= 2;
		AMateria** temp = new AMateria*[_capacity];
		for (int i = 0; i < _size; i++)
			temp[i] = _storage[i];
		delete[] _storage;
		_storage = temp;
	}
	_storage[_size++] = m;
}

void Storage::compareStorage(AMateria* m) {
	if (m == NULL)
		return;
	int j = -1;
	for (int i = 0; i < _size; i++) {
		if (_storage[i] && _storage[i] == m) {
			j = i;
			std::cout << "Materia was found in storage at index " << i << std::endl;
			break;
		}
	}
	if (j >= 0) {
		for (int i = j; i < _size - 1; i++) {
			_storage[i] = _storage[i + 1];
		}
		_storage[_size] = NULL;
		_size--;
	}
}
