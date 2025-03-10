/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:05:35 by ncampbel          #+#    #+#             */
/*   Updated: 2025/03/10 19:22:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &copy);
		MutantStack &operator=(MutantStack const &rhs);	
		~MutantStack();
		
		void push(T value);
		void pop();
		T top();
		size_t size();
		bool empty();
		
		typedef typename std::deque<T>::iterator iterator;
		iterator begin();
		iterator end();
};

# include "MutantStack.tpp"

#endif