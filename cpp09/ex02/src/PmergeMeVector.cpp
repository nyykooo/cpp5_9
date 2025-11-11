/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:24:28 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/11 20:44:13 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

// PRINT METHOD
void PmergeMe::printVec(void) const
{
	std::cout << BLD_CYAN << "PmergeMeVec >> printVec >> _vec: ";
	size_t i;
	size_t length = _vec.size();
	
	for (i = 0; i < length; ++i)
		std::cout << _vec[i] << " ";
	std::cout << RESET << std::endl;
}