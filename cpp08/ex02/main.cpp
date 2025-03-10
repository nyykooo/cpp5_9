/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:40:41 by ncampbel          #+#    #+#             */
/*   Updated: 2025/03/10 19:31:23 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		std::cout << "Testing Mutant Stack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}


	{
		std::cout << "Testing std::stack " << std::endl;

		std::stack<int> std_stack;
		std_stack.push(5);
		std_stack.push(17);
		std::cout << std_stack.top() << std::endl;
		std_stack.pop();
		std::cout << std_stack.size() << std::endl;
		std_stack.push(3);
		std_stack.push(5);
		std_stack.push(737);
		//[...]
		std_stack.push(0);
		// std::stack<int>::iterator it = std_stack.begin();
		// std::stack<int>::iterator ite = std_stack.end();
		// ++it;
		// --it;
		// while (it != ite)
		// {
		// std::cout << *it << std::endl;
		// ++it;
		// }
		std::stack<int> s(std_stack);
	}

	{
		std::cout << "Testing std::list " << std::endl;

		std::list<int> std_list;
		std_list.push_back(5);
		std_list.push_back(17);
		std::cout << std_list.back() << std::endl;
		std_list.pop_back();
		std::cout << std_list.size() << std::endl;
		std_list.push_back(3);
		std_list.push_back(5);
		std_list.push_back(737);
		//[...]
		std_list.push_back(0);
		std::list<int>::iterator it = std_list.begin();
		std::list<int>::iterator ite = std_list.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(std_list);
	}
	return 0;
}