/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:28 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/11 20:44:18 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

// PRINT METHOD
void PmergeMe::printList(void) const
{
	std::cout << BLD_CYAN << "PmergeMeList >> printList >> _list: ";
	std::list<int>::const_iterator it;
	std::list<int>::const_iterator end = _list.end();
	
	for (it = _list.begin(); it != end; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << RESET << std::endl;
}