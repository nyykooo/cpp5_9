/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:21:45 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/22 16:53:44 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, bool sign, int gradeToSign, int gradeToExecute) : _name(name), _signed(sign), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm& AForm::operator=(const AForm& copy) {
	if (this != &copy) {
		_signed = copy._signed;
	}
	return *this;
}

AForm::~AForm(void) {}

std::string		AForm::getName(void) const { return _name; }

bool			AForm::getSigned(void) const { return _signed; }

int				AForm::getGradeToSign(void) const { return _gradeToSign; }

int				AForm::getGradeToExecute(void) const { return _gradeToExecute; }

void			AForm::beSigned(Bureaucrat b) {
	if (b.getGrade() > _gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	else
		std::cout << BLD_BLUE << executor.getName() << RESET << " executes " << BLD_YELLOW << _name << std::endl;
	return ;
}

AForm::GradeTooHighException::GradeTooHighException() {}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char* AForm::GradeTooHighException::what() const throw() {
	return "the grade is too high!";
}

AForm::GradeTooLowException::GradeTooLowException() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char* AForm::GradeTooLowException::what() const throw() {
	return "the grade is too low!";
}

AForm::FormNotSignedException::FormNotSignedException() {}

AForm::FormNotSignedException::~FormNotSignedException() throw() {}

const char* AForm::FormNotSignedException::what() const throw() {
	return "the form is not signed!";
}

std::ostream& operator<<(std::ostream& outputStream, const AForm &form) {
	outputStream << "Form: " << BLD_YELLOW << form.getName() << RESET << " is ";
	if (form.getSigned())
		outputStream << BLD_GREEN << "signed";
	else
		outputStream << BLD_RED << "not signed";
	outputStream << RESET << " and requires a grade of " << UND_GREEN << form.getGradeToSign() << RESET << " to sign and a grade of " << UND_CYAN << form.getGradeToExecute() << RESET << " to execute." << std::endl;
	return outputStream;
}