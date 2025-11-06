/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:28 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/06 21:12:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

// ################ GETTERS ################

std::list<int> PmergeMe::getList()
{
	return _list;
}

std::vector<int> PmergeMe::getVec()
{
	return _vec;
}