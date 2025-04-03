/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:12:40 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/23 16:04:45 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
#include <sys/time.h>
# include "Bureaucrat.hpp"
# include "output.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string		_name;
		bool			_signed;
		int				_gradeToSign;
		int				_gradeToExecute;

	public:
		AForm(void);
		AForm(std::string name, bool sign, int gradeToSign, int gradeToExecute);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm(void);

		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		void			beSigned(Bureaucrat b);
		virtual	void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				virtual ~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				virtual ~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				FormNotSignedException();
				virtual ~FormNotSignedException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const AForm &AForm);

#endif