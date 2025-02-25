/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:44:26 by ncampbel          #+#    #+#             */
/*   Updated: 2025/02/25 19:12:38 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& src) {
	*this = src;
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src) {
	if (this != &src) {
		delete [] _array;
		_size = src._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = src._array[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](int n) {
	if (n >= static_cast<int>(_size) || n < 0) {
		throw std::out_of_range("Index out of range");
	}
	return _array[n];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

