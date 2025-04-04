/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:34:43 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/04 22:22:55 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm created!" << std::endl;
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
		std::cout << "INFORMING: " << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "INFORMING: the robotomy of " << _target << " has failed." << std::endl;
}