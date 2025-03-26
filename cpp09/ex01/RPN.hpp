/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:33:23 by ncampbel          #+#    #+#             */
/*   Updated: 2025/03/26 18:01:58 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN {
	private:
		std::stack<int>	_stack;
		std::string		_input;
		int				_result;
	
	public:
		RPN();
		RPN(std::string input);
		RPN(RPN const &copy);
		~RPN();
		RPN &operator=(RPN const &copy);

		// SETTERS
		void		setInput(std::string input);
		void		setResult(int result);
		
		// GETTERS
		std::string	getInput() const;
		int			getResult() const;

		// MEMBER FUNCTIONS
		void	checkInput(std::string input) const;
		void	calculateRPN(std::string input);
		void	performAddition();
		void	performSubtraction();
		void	performMultiplication();
		void	performDivision();

		// EXCEPTIONS
		class InvalidOperandChar : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class InvalidAmountOfOperands : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class InvalidOperandOrder : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class InvalidAmountEnd : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class InvalidNumber : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif