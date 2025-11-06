/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:55:00 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/05 17:23:11 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
	{
		Intern *intern = NULL;
		Bureaucrat *bureaucrat = NULL;
		AForm *form = NULL;

		try
		{
			std::cout << BLD_GREEN << "\n\n### TESTING INTERN CREATING FORM ###" << RESET << std::endl;
			bureaucrat = new Bureaucrat("Nico", 1);
			intern = new Intern();

			form = intern->makeForm("RobotomyRequest", "PIPIPIPOPOPO");
			bureaucrat->signAForm(*form);
			bureaucrat->executeForm(*form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete bureaucrat;
		delete intern;
		delete form;
	}
	{
		Intern *intern = NULL;
		Bureaucrat *bureaucrat = NULL;
		AForm *form = NULL;

		try
		{
			std::cout << BLD_GREEN << "\n\n### TESTING INTERN FAILING TO CREATE A FORM ###" << RESET << std::endl;
			bureaucrat = new Bureaucrat("Nico", 1);
			intern = new Intern();

			form = intern->makeForm("PipipiPopopoForm", "HeyThere");
			bureaucrat->signAForm(*form);
			bureaucrat->executeForm(*form);
		}
		catch(const std::exception& e)
		{
			std::cerr << BLK_RED << e.what() << RESET << std::endl;
		}
		delete bureaucrat;
		delete intern;
		delete form;
	}
	return 0;
}