/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:28 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/20 19:36:25 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

// ################ LIFE CYCLE ################

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	this->_deque = other._deque;
	this->_vec = other._vec;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if(this != &other)
	{
		this->_deque = other._deque;
		this->_vec = other._vec;
	}
	return *this;
}

// ################ LIFE CYCLE ################

PmergeMe::PmergeMe(int ac, char **av)
{
	if (ac == 0)
		throw PmergeMe::ParseException("Error >> Invalid arguments!\nUsage: ./PmergeMe <list of numbers unsorted>");
	else
	{
		std::string			str;
		std::stringstream	ss;
		char				*endptr = NULL;
		ss << av[1];
		while (ss >> str) {
			long	num;
			errno = 0;
			num = std::strtol(str.c_str(), &endptr, 10);
			if (*endptr || errno == ERANGE || num < 0 || num > INT_MAX)
				throw std::runtime_error(str + " :Invalid input!");
			_vec.push_back(static_cast<int>(num));
			_deque.push_back(static_cast<int>(num));
		}
	}

	std::cout << "Before: ";
	printVec(_vec);
	std::clock_t vecStart = std::clock();
	sortVec();
    std::clock_t vecEnd = std::clock();
    double timeVec = double(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After: ";
	printVec(_vec);


	std::cout << "Before: ";
	printDeque(_deque);
	std::clock_t dequeStart = std::clock();
	sortDeque();
    std::clock_t dequeEnd = std::clock();
    double timeDeque = double(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After: ";
	printDeque(_deque);


    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " << timeDeque << " us" << std::endl;
}

// ################ GETTERS ################

std::deque<int> PmergeMe::getDeque()
{
	return _deque;
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