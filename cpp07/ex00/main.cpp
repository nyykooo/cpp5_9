/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:02:47 by ncampbel          #+#    #+#             */
/*   Updated: 2025/02/06 17:52:42 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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

	std::cout << "Before swap: " << str1 << ", " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "After swap: " << str1 << ", " << str2 << std::endl;
	
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Min: " << min(str1, str2) << std::endl;	
	std::cout << "Max: " << max(str1, str2) << std::endl;
	
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Min: " << min(str2, str3) << std::endl;	
	std::cout << "Max: " << max(str2, str3) << std::endl;

	std::cout << "--------------------------------" << std::endl;
	str1 = "string1";
	std::cout << "Min: " << min(str1, str4) << std::endl;
	std::cout << "Max: " << max(str1, str4) << std::endl;

	int a = 21;
	int b = 42;
	int c = 84;
	int d = 21;

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Before swap: " << a << ", " << b << std::endl;
	swap(a, b);
	std::cout << "After swap: " << a << ", " << b << std::endl;

	std::cout << "--------------------------------" << std::endl;
	std::cout << "Min: " << min(a, b) << std::endl;
	std::cout << "Max: " << max(a, b) << std::endl;
	
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Min: " << min(b, c) << std::endl;
	std::cout << "Max: " << max(b, c) << std::endl;
	
	std::cout << "--------------------------------" << std::endl;
	a = 21;
	std::cout << "Min: " << min(a, d) << std::endl;
	std::cout << "Max: " << max(a, d) << std::endl;
	return (0);	
}