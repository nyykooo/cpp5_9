/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:55:00 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/04 23:22:02 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
	{
		Intern *intern;
		Bureaucrat *bureaucrat;
		AForm *form;

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
		
	}
	{
		Intern *intern;
		Bureaucrat *bureaucrat;
		AForm *form;

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
		
	}
	return 0;
}