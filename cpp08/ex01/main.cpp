/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:43:16 by ncampbel          #+#    #+#             */
/*   Updated: 2025/02/27 19:26:13 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << " ### SUBJECT TESTS ### " << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << " ### MORE TESTS ### " << std::endl;
	{
		Span sp = Span(100000);
		std::vector<int> v(100000, 0);
		v[0] = -42;
		v[99999] = 42;
		std::vector<int>::iterator begin = v.begin();
		std::vector<int>::iterator end = v.end();

		sp.addManyNumbers(begin, end);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		try
		{
			sp.addNumber(42);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

		Span sp2 = Span(1);
		try
		{
			sp2.shortestSpan();
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}