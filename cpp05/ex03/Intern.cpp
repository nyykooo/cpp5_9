/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:02:42 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/04 23:10:48 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const & src)
{
	(void)src;
	return (*this);
}

static AForm *createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm *(*formCreatorsFunctions[3])(std::string) = {createShrubberyCreationForm, createRobotomyRequestForm, createPresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << BLD_MAGENTA << "Intern " << RESET << "creates " << BLD_YELLOW << formName << std::endl;
			return (formCreatorsFunctions[i](target));
		}
	}

	throw Intern::UnknownFormException();
	return (NULL);
}

Intern::UnknownFormException::UnknownFormException()
{
}

Intern::UnknownFormException::~UnknownFormException() throw()
{
}

const char* Intern::UnknownFormException::what() const throw()
{
	return ("Intern doesn't know this form type yet");
}
