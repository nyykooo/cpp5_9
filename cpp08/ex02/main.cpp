/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:40:41 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/27 19:21:30 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
# include <list>

// Função auxiliar para usar com std::for_each (C++98)
void printDouble(int n) {
	std::cout << n * 2 << " ";
}

// Função auxiliar para exemplo adicional
void printSquare(int n) {
	std::cout << n * n << " ";
}


int main()
{
	std::cout << BLD_CYAN << "###### SUBJECT TEST ######" << RESET << std::endl;
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
	
	std::cout << BLD_CYAN << "###### MORE TEEEESTS!!! ######" << RESET << std::endl;
	{
		std::cout << BLD_GREEN << "\n1. MUTANT STACK BASIC TESTS" << RESET << std::endl;
		MutantStack<int> mstack;
		
		// Teste de push e size
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		std::cout << BLD_MAGENTA << "Top: " << RESET << mstack.top() << std::endl;
		std::cout << BLD_MAGENTA << "Size: " << RESET << mstack.size() << std::endl;
	}

	{
		std::cout << BLD_GREEN << "\n2. NORMAL ITERATORS (forward)" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);
		mstack.push(30);
		mstack.push(40);
		mstack.push(50);

		std::cout << BLD_MAGENTA << "printing elements: " << RESET;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		for (; it != ite; ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		// Teste de decremento
		std::cout << BLD_MAGENTA << "incrementing: " << RESET;
		it = mstack.begin();
		++it;
		std::cout << *it << std::endl;
	}

	{
		std::cout << BLD_GREEN << "\n3. REVERSE ITERATORS" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		std::cout << BLD_MAGENTA << "printing elements: " << RESET;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		
		for (; rit != rite; ++rit) {
			std::cout << *rit << " ";
		}
		std::cout << std::endl;

		// Teste de decremento com reverse iterator
		std::cout << BLD_MAGENTA << "incrementing: " << RESET;
		rit = mstack.rbegin();
		++rit;
		std::cout << *rit << std::endl;
	}

	{
		std::cout << BLD_GREEN << "\n4. CONST ITERATORS" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(100);
		mstack.push(200);
		mstack.push(300);

		const MutantStack<int>& const_mstack = mstack;

		std::cout << BLD_MAGENTA << "printing elements: " << RESET;
		MutantStack<int>::const_iterator cit = const_mstack.begin();
		MutantStack<int>::const_iterator cite = const_mstack.end();
		
		for (; cit != cite; ++cit) {
			std::cout << *cit << " ";
			// *cit = 999; // this causes a compilation error because cit is constant!
		}
		std::cout << std::endl;

		std::cout << BLD_MAGENTA << "printing elements: " << RESET;
		MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
		MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
		
		for (; crit != crite; ++crit) {
			std::cout << *crit << " ";
		}
		std::cout << std::endl;
	}

	{
		std::cout << BLD_GREEN << "\n5. TESTING WITH STL ALGORITHMS" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		
		std::cout << BLD_MAGENTA << "std::find: " << RESET;
		MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 3);
		if (found != mstack.end())
			std::cout << "found! " << *found << std::endl;
		else
			std::cout << UND_RED << "not found... " << *found << std::endl;
		std::cout << BLD_MAGENTA << "std::find: " << RESET;
		MutantStack<int>::iterator found2 = std::find(mstack.begin(), mstack.end(), 99);
		if (found2 != mstack.end())
			std::cout << "found! " << *found2 << std::endl;
		else
			std::cout << UND_RED << "value not found..." << RESET << std::endl;

		std::cout << BLD_MAGENTA << "std::count: " << RESET;
		int count = std::count(mstack.begin(), mstack.end(), 2);
		std::cout << count << std::endl;

		std::cout << BLD_MAGENTA << "std::for_each printDouble: " << RESET;
		std::for_each(mstack.begin(), mstack.end(), printDouble);
		std::cout << std::endl;

		// Exemplo adicional com outra função
		std::cout << BLD_MAGENTA << "std::for_each printSquare: " << RESET;
		std::for_each(mstack.begin(), mstack.end(), printSquare);
		std::cout << std::endl;
	}
		

	{
		std::cout << BLD_GREEN << "\n6. TESTING COPY AND ASSIGNING" << RESET << std::endl;
		MutantStack<int> original;
		original.push(7);
		original.push(8);
		original.push(9);

		// Teste de cópia
		MutantStack<int> copy(original);
		std::cout << BLD_MAGENTA << "copy (forward): " << RESET;
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << BLD_MAGENTA << "copy (reverse): " << RESET;
		for (MutantStack<int>::reverse_iterator it = copy.rbegin(); it != copy.rend(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		// Teste de atribuição
		MutantStack<int> assigned;
		assigned = original;
		std::cout << BLD_MAGENTA << "assigned: " << RESET;
		for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	{
		std::cout << BLD_GREEN << "\n7. COMPAIRING WITH STD::LIST" << RESET << std::endl;
		MutantStack<int> mstack;
		std::list<int> lst;

		// Preenchendo ambos com os mesmos valores
		for (int i = 1; i <= 5; i++) {
			mstack.push(i);
			lst.push_back(i);
		}

		std::cout << BLD_MAGENTA << "MutantStack: " << RESET;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << BLD_MAGENTA << "std::list: " << RESET;
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << BLD_MAGENTA << "MutantStack (reverse): " << RESET;
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << BLD_MAGENTA << "std::list (reverse): " << RESET;
		for (std::list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}