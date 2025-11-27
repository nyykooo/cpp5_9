/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:58:53 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/27 18:12:41 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "macros.hpp"

template <typename T>
void	print(T value)
{
	std::cout << value << std::endl;
}

void	toUper(const std::string &str)
{
		std::string upperStr = str;
		for (size_t i = 0; i < upperStr.length(); i++)
			upperStr[i] = toupper(upperStr[i]);
		std::cout << upperStr << std::endl;
}

void	square(const int &i)
{
	std::cout << i * i << std::endl;
}

template <typename T, typename F>
void	iter(T *array, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

int main(void)
{
	std::string str[] = {"string1", "string2", "string3", "string4", "string5"};
	int intArr[] = {1, 2, 3, 4, 5};
	
	std::cout << BLD_CYAN << "STRING ARRAY" << RESET << std::endl;
	iter<std::string>(str, 5, print);
	std::cout << BLD_CYAN << "----------------" << RESET << std::endl;
	
	std::cout << BLD_CYAN << "To Upper!!!" << RESET << std::endl;
	iter<std::string>(str, 5, toUper);
	std::cout << BLD_CYAN << "----------------" << RESET << std::endl;
	
	std::cout << BLD_CYAN << "INT ARRAY" << RESET << std::endl;
	iter<int>(intArr, 5, print);
	std::cout << BLD_CYAN << "----------------" << RESET << std::endl;
	
	std::cout << BLD_CYAN << "Square It!" << RESET << std::endl;
	iter<int>(intArr, 5, square);
	std::cout << BLD_CYAN << "----------------" << RESET << std::endl;
	return (0);
}