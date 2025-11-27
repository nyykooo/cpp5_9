/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:44:29 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/25 18:25:22 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	{
		try 
		{
			Array<int> intArray(51);
			Array<std::string> stringArray(50);
			
			std::cout << "Int Array Before: ";
			for (unsigned int i = 0; i < intArray.size(); i++) {
				std::cout << intArray[i] << " ";
			}
			std::cout << std::endl;
			
			std::cout << "Int Array After: ";
			for (unsigned int i = 0; i < intArray.size(); i++) {
				intArray[i] = i;
				std::cout << intArray[i] << " ";
			}
			std::cout << std::endl;
			
			std::cout << "String Array: ";
			for (unsigned int i = 0; i < stringArray.size(); i++) {
			std::stringstream ss;
				ss << "String" << i;
				stringArray[i] = ss.str();
				std::cout << stringArray[i] << " ";
			}
			std::cout << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << BLD_RED << e.what() << RESET << std::endl;
		}
	}
	
	{
		try 
		{
			Array<int> intArray(51);
			std::cout << intArray[52] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << BLD_RED << e.what() << RESET << std::endl;
		}
	}
	return (0);
}