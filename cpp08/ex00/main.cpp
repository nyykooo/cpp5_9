/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:11:13 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/25 18:45:14 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	try{
		std::cout << "-----------------" << std::endl;
		std::cout << BLD_CYAN << "TESTING VECTOR" << RESET << std::endl;
		
		std::vector<int> vec;
		
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		
		std::cout << BLD_GREEN << easyfind(vec, 3) << RESET << std::endl;
		std::cout << BLD_GREEN << easyfind(vec, 6) << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BLD_RED << e.what() << RESET << std::endl;
	}

	try{
		std::cout << "-----------------" << std::endl;
		std::cout << BLD_CYAN << "TESTING LIST" << RESET << std::endl;
		
		std::list<int> lst;
		
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);
		
		std::cout << BLD_GREEN << easyfind(lst, 3) << RESET << std::endl;
		std::cout << BLD_GREEN << easyfind(lst, -1) << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BLD_RED << e.what() << RESET << std::endl;
	}

	try{
		std::cout << "-----------------" << std::endl;
		std::cout << BLD_CYAN << "TESTING DEQUE" << RESET << std::endl;
		
		std::deque<int> deq;
		
		deq.push_back(1);
		deq.push_back(2);
		deq.push_back(3);
		deq.push_back(4);
		deq.push_back(5);
		
		std::cout << BLD_GREEN << easyfind(deq, 3) << RESET << std::endl;
		std::cout << BLD_GREEN << easyfind(deq, 5) << RESET << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BLD_RED << e.what() << RESET << std::endl;
	}
}