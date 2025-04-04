/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:38:32 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/04 23:22:17 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
{
	std::cout << UND_CYAN << "ShrubberyCreationForm created!" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		_target = src._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::ofstream outFile(this->getTarget().append("_shrubbery").c_str());
	outFile << "      ###       " << std::endl;
	outFile << "     #0###       " << std::endl;
	outFile << "    #####O##      " << std::endl;
	outFile << "   #0#\\\\#####   " << std::endl;
	outFile << "  #####@#######O#  " << std::endl;
	outFile << "  ####O##//####" << std::endl;
	outFile << "  #####O//###" << std::endl;
	outFile << "      ||      " << std::endl;
	outFile << "      ||      " << std::endl;
	outFile << "      ||      " << std::endl;
	outFile << " __^^_||_^^__ " << std::endl;
	outFile << std::endl;
	outFile.close();
}