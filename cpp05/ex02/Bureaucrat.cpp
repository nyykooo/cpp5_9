/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:42:15 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/03 19:34:23 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy._name), _grade(copy._grade)
{
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
		_grade = copy._grade;
	return (*this);
}

std::string const Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << BLD_BLUE << _name << RESET << " grade incremented to " << BLD_GREEN << _grade << RESET << std::endl;
	return ;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << BLD_BLUE << _name << RESET << " grade decremented to " << BLD_RED << _grade << RESET << std::endl;
	return ;
}

void Bureaucrat::signAForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << BLD_BLUE << this->getName() << RESET << " signs " << BLD_YELLOW << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BLK_RED << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
	return ;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &error)
	{
		std::cout << BLK_RED << this->getName() << " couldn't execute " << form.getName() << " because " << error.what() << RESET << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
   return "Grade too high!";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &bureaucrat)
{
	outputStream << BLD_BLUE << bureaucrat.getName() << UND_WHITE << ", bureaucrat grade " << RESET << BLD_MAGENTA << bureaucrat.getGrade() << RESET << std::endl;
	return (outputStream);	
}