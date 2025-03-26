/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:33:46 by ncampbel          #+#    #+#             */
/*   Updated: 2025/03/25 19:18:25 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


// ### ORTHODOX CANONICAL FORM ###
RPN::RPN() : _input(""), _result(0) {}

RPN::RPN(std::string input)
{
	_result = 0;
	setInput(input);
	checkInput(input);
	calculateRPN(input);
}

RPN::RPN(RPN const &copy) {
	*this = copy;
}

RPN::~RPN() {}

RPN &RPN::operator=(RPN const &copy) {
	if (this != &copy) {
		this->_input = copy._input;
		this->_result = copy._result;
		this->_stack = copy._stack;
	}
	return *this;
}


// ### SETTERS ###
void	RPN::setInput(std::string input) {
	this->_input = input;
}

void	RPN::setResult(int result) {
	this->_result = result;
}


// ### GETTERS ###
std::string	RPN::getInput() const {
	return this->_input;
}

int			RPN::getResult() const {
	return this->_result;
}

// ### MEMBER FUNCTIONS ###
void RPN::checkInput(std::string input) const
{
	size_t quantityNumbers = 0;
	size_t quantityOperators = 0;
	std::string::const_iterator it = input.begin();
	while (it != input.end())
	{
		if (!isdigit(*it) && *it != '+' && *it != '-' && *it != '*' && *it != '/' && *it != ' ')
			throw RPN::InvalidOperandChar();
		else if (isdigit(*it))
		{
			if (isdigit(*(it + 1)))
				throw RPN::InvalidNumber();
			else
				quantityNumbers++;
		}
		else if (*it != ' ')
			quantityOperators++;	
		it++;
	}
	if (quantityNumbers - quantityOperators != 1)
		throw RPN::InvalidAmountOfOperands();
}

void RPN::calculateRPN(std::string input)
{
	std::string::const_iterator it = input.begin();
	while (it != input.end())
	{
		if (isdigit(*it))
			this->_stack.push((*it - '0'));
		else if (*it != ' ')
		{
			if (this->_stack.size() < 2)
				throw RPN::InvalidOperandOrder();
			else if (*it == '+')
				performAddition();
			else if (*it == '-')
				performSubtraction();
			else if (*it == '*')
				performMultiplication();
			else if (*it == '/')
				performDivision();
		}
		it++;
	}
	if (this->_stack.size() != 1)
		throw RPN::InvalidAmountEnd();
	this->_result = this->_stack.top();
}

void RPN::performAddition()
{
	int a = this->_stack.top();
	this->_stack.pop();
	int b = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(a + b);
}

void RPN::performSubtraction()
{
	int a = this->_stack.top();
	this->_stack.pop();
	int b = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(- a + b);
}

void RPN::performMultiplication()
{
	int a = this->_stack.top();
	this->_stack.pop();
	int b = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(a * b);
}

void RPN::performDivision()
{
	int a = this->_stack.top();
	this->_stack.pop();
	int b = this->_stack.top();
	this->_stack.pop();
	this->_stack.push(a / b);
}

// ### EXCEPTIONS ###
const char* RPN::InvalidOperandChar::what() const throw()
{
	return "Error: Invalid operand character";
}

const char* RPN::InvalidAmountOfOperands::what() const throw()
{
	return "Error: Invalid amount of operands";
}

const char* RPN::InvalidOperandOrder::what() const throw()
{
	return "Error: Invalid operand order";
}

const char* RPN::InvalidAmountEnd::what() const throw()
{
	return "Error: Invalid amount at end";
}

const char* RPN::InvalidNumber::what() const throw()
{
	return "Invalid number";
}
