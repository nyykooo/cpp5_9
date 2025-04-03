/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:55:00 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/03 20:37:09 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{
	{
		std::cout << BLD_GREEN << "\n\n### TESTING SHRUBBERRYCREATIONFORM ###" << RESET << std::endl;
		Bureaucrat *b1 = NULL;
		AForm *f1 = NULL;

		try
		{
			b1 = new Bureaucrat("Nico", 1);
			f1 = new ShrubberyCreationForm("Tree");

			std::cout << *b1;
			std::cout << *f1;
			
			std::cout << BLD_GREEN << "\n### SIGNING SCF ###" << RESET << std::endl;
			b1->signAForm(*f1);
		
			std::cout << BLD_GREEN << "\n### EXECUTING SCF ###" << RESET << std::endl;
			b1->executeForm(*f1);
			
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}

		delete b1;
		delete f1;
	}
	{
		std::cout << BLD_GREEN << "\n\n### TESTING PRESIDENTIALPARDONFORM ###" << RESET << std::endl;
		Bureaucrat *b1 = NULL;
		AForm *f1 = NULL;

		try
		{
			b1 = new Bureaucrat("Nico", 1);
			f1 = new PresidentialPardonForm("Xorbelbeeb Dofaz");

			std::cout << *b1;
			std::cout << *f1;
			
			std::cout << BLD_GREEN << "\n### SIGNING PPF ###" << RESET << std::endl;
			b1->signAForm(*f1);
		
			std::cout << BLD_GREEN << "\n### EXECUTING PPF ###" << RESET << std::endl;
			b1->executeForm(*f1);
			
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}

		delete b1;
		delete f1;
	}
	{
		std::cout << BLD_GREEN << "\n\n### TESTING ROBOTOMYREQUESTFORM ###" << RESET << std::endl;
		Bureaucrat *b1 = NULL;
		AForm *f1 = NULL;

		try
		{
			b1 = new Bureaucrat("Nico", 1);
			f1 = new RobotomyRequestForm("C3P0");

			std::cout << *b1;
			std::cout << *f1;
			
			std::cout << BLD_GREEN << "\n### SIGNING RRF ###" << RESET << std::endl;
			b1->signAForm(*f1);
		
			std::cout << BLD_GREEN << "\n### EXECUTING RRF ###" << RESET << std::endl;
			b1->executeForm(*f1);
			b1->executeForm(*f1);
			b1->executeForm(*f1);
			b1->executeForm(*f1);
			b1->executeForm(*f1);
			b1->executeForm(*f1);
			b1->executeForm(*f1);
			b1->executeForm(*f1);
			b1->executeForm(*f1);
			b1->executeForm(*f1);
			
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}

		delete b1;
		delete f1;
	}
	{
		std::cout << BLD_GREEN << "\n\n### TESTING EXECUTE WITHOUT SIGNING ###" << RESET << std::endl;
		Bureaucrat *b1 = NULL;
		AForm *f1 = NULL;

		try
		{
			b1 = new Bureaucrat("Nico", 1);
			f1 = new ShrubberyCreationForm("Tree");

			std::cout << *b1;
			std::cout << *f1;
		
			std::cout << BLD_GREEN << "\n### EXECUTING SCF ###" << RESET << std::endl;
			b1->executeForm(*f1);
			
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}

		delete b1;
		delete f1;
	}
	{
		std::cout << BLD_GREEN << "\n\n### TESTING EXECUTE WITHOUT GRADE ###" << RESET << std::endl;
		Bureaucrat *b1 = NULL;
		AForm *f1 = NULL;

		try
		{
			b1 = new Bureaucrat("Nico", 138);
			f1 = new ShrubberyCreationForm("Tree");

			std::cout << *b1;
			std::cout << *f1;

			std::cout << BLD_GREEN << "\n### SIGNING ###" << RESET << std::endl;
			b1->signAForm(*f1);
		
			std::cout << BLD_GREEN << "\n### EXECUTING ###" << RESET << std::endl;
			b1->executeForm(*f1);
			
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}

		delete b1;
		delete f1;
	}
	return 0;
}