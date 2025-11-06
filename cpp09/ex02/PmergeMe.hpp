/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:14:54 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/06 21:10:52 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "iostream"
#include "vector"
#include "list"

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::list<int>		_list;
		
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &other);

		// GETTERS
		std::list<int>		getList();
		std::vector<int>	getVec();
};

#endif