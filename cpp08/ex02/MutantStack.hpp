/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:05:35 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/27 19:44:28 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>
# include "macros.hpp"

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
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		iterator begin();
		iterator end();
		
		const_iterator begin() const;
		const_iterator end() const;
		
		reverse_iterator rbegin();
		reverse_iterator rend();
		
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"

#endif