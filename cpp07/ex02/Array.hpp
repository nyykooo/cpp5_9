/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:44:31 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/25 18:15:31 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include "macros.hpp"

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_size;
		
	public:
		Array();
		explicit Array(unsigned int n);
		Array(const Array& src);

		~Array();

		Array& operator=(const Array& src);
		T& operator[](int n);
		unsigned int	size() const;

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif