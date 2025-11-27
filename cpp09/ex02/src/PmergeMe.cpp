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

PmergeMe::PmergeMe() : _compairsons(0)
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

static int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return (sum);
}

PmergeMe::PmergeMe(int ac, char **av) : _compairsons(0)
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
			_list.push_back(static_cast<int>(num));
		}
	}
	sortVec();
	std::cout << "compairsons made to vec: " << _compairsons << std::endl;
	_compairsons = 0;
	sortList();
	std::cout << "MAX EXPECTED COMPAIRSONS: " << F(_vec.size()) << std::endl;
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