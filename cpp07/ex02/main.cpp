/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:44:29 by ncampbel          #+#    #+#             */
/*   Updated: 2025/02/25 19:16:16 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int> intArray(5);
	Array<std::string> stringArray(5);
	
	std::cout << "Int Array Before: ";

	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << intArray[i] << " ";
	}
	
	std::cout << std::endl << "Int Array After: ";
	
	for (unsigned int i = 0; i < intArray.size(); i++) {
		intArray[i] = i;
		std::cout << intArray[i] << " ";
	}

	std::cout << std::endl << "String Array: ";

	for (unsigned int i = 0; i < stringArray.size(); i++) {
		stringArray[i] = "String" + i;
		std::cout << stringArray[i] << " ";
	}

	std::cout << std::endl;
	return (0);
}