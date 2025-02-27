/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:17:36 by ncampbel          #+#    #+#             */
/*   Updated: 2025/02/27 19:23:38 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>

class Span{
	private:
		unsigned int _n;
		std::vector<int> _container;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		~Span();
		Span & operator=(Span const & src);

		void addNumber(int n);
		void addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();

		class FullSpanException : public std::exception {
			public:
				FullSpanException();
				virtual ~FullSpanException() throw();
				virtual const char* what() const throw();
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				NotEnoughNumbersException();
				virtual ~NotEnoughNumbersException() throw();
				virtual const char* what() const throw();
		};
};

#endif