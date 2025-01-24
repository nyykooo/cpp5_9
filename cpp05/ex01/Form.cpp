/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:21:45 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/24 16:00:22 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute, bool sign) : _name(name), _signed(sign), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form& Form::operator=(const Form& copy) {
	if (this != &copy) {
		_signed = copy._signed;
	}
	return *this;
}

Form::~Form(void) {}

std::string		Form::getName(void) const { return _name; }

bool			Form::getSigned(void) const { return _signed; }

int				Form::getGradeToSign(void) const { return _gradeToSign; }

int				Form::getGradeToExecute(void) const { return _gradeToExecute; }

void			Form::beSigned(Bureaucrat b) {
	try
	{
		if (b.getGrade() > _gradeToSign)
		{
			std::cout << b.getName() << " couldn’t sign " << _name << " because ";
			throw Form::GradeTooLowException();
		}
		b.signForm();
		_signed = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high!";
}

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}

std::ostream& operator<<(std::ostream& outputStream, const Form &form) {
	outputStream << "Form: " << form.getName() << " is ";
	if (form.getSigned())
		outputStream << "signed";
	else
		outputStream << "not signed";
	outputStream << " and requires a grade of " << form.getGradeToSign() << " to sign and a grade of " << form.getGradeToExecute() << " to execute." << std::endl;
	return outputStream;
}