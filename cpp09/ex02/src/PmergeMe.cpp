/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:28 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/11 21:26:05 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

// ################ LIFE CYCLE ################

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	this->_list = other._list;
	this->_vec = other._vec;
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if(this != &other)
	{
		this->_list = other._list;
		this->_vec = other._vec;
	}
	return *this;
}

// ################ LIFE CYCLE ################

PmergeMe::PmergeMe(int ac, char **av)
{
	if (ac <= 1)
		throw PmergeMe::ParseException("Error >> Invalid arguments!\nUsage: ./PmergeMe <list of numbers unsorted>");
	else
	{
		std::cout << BLD_GREEN << "Before: ";
		for (int i = 1; i < ac; ++i)
		{
			_vec.push_back(std::atoi(av[i]));
			_list.push_back(std::atoi(av[i]));
			std::cout << av[i] << " ";
		}
		std::cout << RESET << std::endl;
	}
	sortVec();
	sortList();
}


// ################ GETTERS ################

std::list<int> PmergeMe::getList()
{
	return _list;
}

std::vector<int> PmergeMe::getVec()
{
	return _vec;
}

// ################ EXCEPTIONS ################
PmergeMe::ParseException::ParseException(const char *msg) : _message(msg) {}

const char *PmergeMe::ParseException::what() const throw()
{
	return _message;
}