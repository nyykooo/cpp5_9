/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:28:42 by ncampbel          #+#    #+#             */
/*   Updated: 2025/03/10 19:23:25 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &copy) : std::stack<T>(copy)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
void MutantStack<T>::push(T value)
{
	std::stack<T>::push(value);
}

template <typename T>
void MutantStack<T>::pop()
{
	std::stack<T>::pop();
}

template <typename T>
T MutantStack<T>::top()
{
	return (std::stack<T>::top());
}

template <typename T>
size_t MutantStack<T>::size()
{
	return (std::stack<T>::size());
}

template <typename T>
bool MutantStack<T>::empty()
{
	return (std::stack<T>::empty());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}
