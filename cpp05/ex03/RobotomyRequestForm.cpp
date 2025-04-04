/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:34:43 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/04 23:20:47 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{
	std::cout << UND_CYAN << "RobotomyRequestForm created!" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		_target = src._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{

	std::srand(std::clock());
	int exec = std::rand() % 2;
	
	AForm::execute(executor);
	std::cout << "Pzz PzzzzzZZZZZZz Pz Pzzzz" << std::endl;
	if (exec)
		std::cout << UND_RED << "INFORMING:" << RESET << " " << BLD_YELLOW << _target << RESET << " has been robotomized successfully." << std::endl;
	else
		std::cout << UND_RED << "INFORMING:" << RESET << " the robotomy of " << BLD_YELLOW << _target << RESET << " has failed." << std::endl;
}