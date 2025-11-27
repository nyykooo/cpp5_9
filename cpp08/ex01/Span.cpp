/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:52:50 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/27 17:38:00 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n), _container(std::vector<int>(0)) {
}

Span::Span(Span const & src){
	*this = src;
}

Span::~Span() {}

Span & Span::operator=(Span const & src){
	if (this != &src){
		_n = src._n;
		_container = src._container;
	}
	return *this;
}

Span::FullSpanException::FullSpanException() {}

Span::FullSpanException::~FullSpanException() throw() {}

const char* Span::FullSpanException::what() const throw()
{
	return "The span is full.";
}
Span::NotEnoughNumbersException::NotEnoughNumbersException() {}

Span::NotEnoughNumbersException::~NotEnoughNumbersException() throw() {}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to calculate span.";
}

void Span::addNumber(int n){
	if (_container.size() == _n)
		throw Span::FullSpanException();
	_container.push_back(n);
}

int Span::shortestSpan()
{
	if (_container.size() < 2)
		throw Span::NotEnoughNumbersException();
	std::vector<int> sorted = _container;
	std::sort(sorted.begin(), sorted.end());
	int shortest = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < sorted.size(); i++)
	{
		if (sorted[i] - sorted[i - 1] < shortest)
			shortest = sorted[i] - sorted[i - 1];
	}
	return shortest;
}

int Span::longestSpan()
{
	if (_container.size() < 2)
		throw Span::NotEnoughNumbersException();
	std::vector<int> sorted = _container;
	std::sort(sorted.begin(), sorted.end());
	return sorted[sorted.size() - 1] - sorted[0];
}

void Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_container.size() + std::distance(begin, end) > _n)
		throw Span::FullSpanException();
	std::cout << BLD_GREEN << "Adding " << std::distance(begin, end) << " numbers." << RESET << std::endl;
	_container.insert(_container.end(), begin, end);
}

