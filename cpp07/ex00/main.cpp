/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:02:47 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/25 17:27:30 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "macros.hpp"

template <typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>
T max(T &a, T &b)
{
	return (a > b ? a : b);
}

int main(void)
{
	std::string str1 = "string1";
	std::string str2 = "string2";
	std::string str3 = "string3";
	std::string str4 = "string1";
	int a = 21;
	int b = 42;
	int c = 84;
	int d = 21;

	std::cout << BLD_CYAN << "----- TESTING SWAP -----" << RESET << std::endl;
	std::cout << BLD_GREEN << "String:" << RESET << std::endl;
	std::cout << "Before swap: " << str1 << ", " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "After swap: " << str1 << ", " << str2 << std::endl;
	std::cout << BLD_GREEN << "Int:" << RESET << std::endl;
	std::cout << "Before swap: " << a << ", " << b << std::endl;
	swap(a, b);
	std::cout << "After swap: " << a << ", " << b << std::endl;

	
	std::cout << "--------------------------------" << std::endl;
	std::cout << BLD_CYAN << "----- TESTING MIN/MAX -----" << RESET << std::endl;
	std::cout << BLD_GREEN << "String:" << RESET << std::endl;
	std::cout << BLD_GREEN << "Testing between str1 (" << str1 << ") and str2 (" << str2 << "):" << RESET << std::endl;
	std::cout << "Min: " << min(str1, str2) << std::endl;	
	std::cout << "Max: " << max(str1, str2) << std::endl;
	std::cout << BLD_GREEN << "Testing between str2 (" << str2 << ") and str3 (" << str3 << "):" << RESET << std::endl;
	std::cout << "Min: " << min(str2, str3) << std::endl;	
	std::cout << "Max: " << max(str2, str3) << std::endl;
	std::cout << BLD_GREEN << "Testing between str1 (" << str1 << ") and str4 (" << str4 << "):" << RESET << std::endl;
	str1 = "string1";
	std::cout << "Min: " << min(str1, str4) << std::endl;
	std::cout << "Max: " << max(str1, str4) << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << BLD_GREEN << "Int:" << RESET << std::endl;
	std::cout << BLD_GREEN << "Testing between a (" << a << ") and b (" << b << "):" << RESET << std::endl;
	std::cout << "Min: " << min(a, b) << std::endl;
	std::cout << "Max: " << max(a, b) << std::endl;
	std::cout << BLD_GREEN << "Testing between b (" << b << ") and c (" << c << "):" << RESET << std::endl;
	std::cout << "Min: " << min(b, c) << std::endl;
	std::cout << "Max: " << max(b, c) << std::endl;
	std::cout << BLD_GREEN << "Testing between a (" << a << ") and d (" << d << "):" << RESET << std::endl;
	a = 21;
	std::cout << "Min: " << min(a, d) << std::endl;
	std::cout << "Max: " << max(a, d) << std::endl;
	return (0);	
}