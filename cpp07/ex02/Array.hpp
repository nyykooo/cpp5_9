/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:44:31 by ncampbel          #+#    #+#             */
/*   Updated: 2025/02/25 19:10:58 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_size;
		
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& src);

		~Array();

		Array& operator=(const Array& src);
		T& operator[](int n);
		unsigned int	size() const;
};

#include "Array.tpp"

#endif