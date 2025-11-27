/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:43:16 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/27 17:49:18 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << BLD_CYAN << "\n### SUBJECT TESTS ###" << RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << BLD_GREEN << "Shortest Span: " << RESET << sp.shortestSpan() << std::endl;
		std::cout << BLD_GREEN << "Largest Span: " << RESET << sp.longestSpan() << std::endl;
	}

	std::cout << BLD_CYAN << "\n### MORE TESTS ###" << RESET << std::endl;
	{
		Span sp = Span(100000);
		std::vector<int> v(100000, 0);
		for (int i = 0; i < 100000; i++)
			v[i] = i * 2;
		std::vector<int>::iterator begin = v.begin();
		std::vector<int>::iterator end = v.end();

		sp.addManyNumbers(begin, end);
		std::cout << BLD_GREEN << "Shortest Span: " << RESET << sp.shortestSpan() << std::endl;
		std::cout << BLD_GREEN << "Largest Span: " << RESET << sp.longestSpan() << std::endl;
		
		std::cout << BLD_CYAN << "\n### EXCEPTION TESTS - FULL ###" << RESET << std::endl;
		try
		{
			sp.addNumber(42);
		}
		catch (std::exception & e)
		{
			std::cout << UND_RED << e.what() << std::endl;
		}

		std::cout << BLD_CYAN << "\n### EXCEPTION TESTS - NOT ENOUGH NUMBERS ###" << RESET << std::endl;
		Span sp2 = Span(1);
		try
		{
			sp2.shortestSpan();
		}
		catch (std::exception & e)
		{
			std::cout << UND_RED << e.what() << RESET << std::endl;
		}
		Span sp3 = Span(1);
		try
		{
			sp3.shortestSpan();
		}
		catch (std::exception & e)
		{
			std::cout << UND_RED << e.what() << RESET << std::endl;
		}
	}
	return 0;
}