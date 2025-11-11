/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:14:54 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/11 19:18:37 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "headers.hpp"

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::list<int>		_list;
		
	public:
		// ORTHODOX CANONICAL FORM
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &other);

		// LIFE CYCLE
		PmergeMe(int ac, char** av);

		// GETTERS
		std::list<int>		getList();
		std::vector<int>	getVec();


		// EXCEPTIONS
		class ParseException : public std::exception
		{
			private:
				const char	*_message;

			public:
				ParseException(const char *msg);

				const char *what() const throw();
		};
};

#endif