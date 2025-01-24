/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:55:00 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/24 15:39:51 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{
	{
		std::cout << "### CREATING BUREAUCRATS AND FORMS ###" << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Nico", 1);
		Bureaucrat *b2 = new Bureaucrat("Campbell", 45);
		Bureaucrat *b3 = new Bureaucrat("PI", 150);
		AForm *f1 = new ShrubberyCreationForm("Tree");
		AForm *f2 = new RobotomyRequestForm("Robot");
		AForm *f3 = new PresidentialPardonForm("Criminal");

		std::cout << std::endl << "### BUREAUCRATS ###" << std::endl;
		std::cout << "Bureaucrat 1: " << *b1;
		std::cout << "Bureaucrat 2: " << *b2;
		std::cout << "Bureaucrat 3: " << *b3;

		std::cout << std::endl << "### FORMS ###" << std::endl;
		std::cout << "ShrubberyCreationForm: " << *f1;
		std::cout << "RobotomyRequestForm: " << *f2;
		std::cout << "PresidentialPardonForm: " << *f3;
		
		std::cout << std::endl << "### SIGNING FORMS ###" << std::endl;
		std::cout << "Bureaucrat 1:" << std::endl;
		f1->beSigned(*b1);
		f2->beSigned(*b1);
		f3->beSigned(*b1);
		
		std::cout << "Bureaucrat 2:" << std::endl;
		f1->beSigned(*b2);
		f2->beSigned(*b2);
		f3->beSigned(*b2);
		
		std::cout << "Bureaucrat 3:" << std::endl;
		f1->beSigned(*b3);
		f2->beSigned(*b3);
		f3->beSigned(*b3);
	
		std::cout << std::endl << "### EXECUTING FORMS ###" << std::endl;
		std::cout << "Bureaucrat 1:" << std::endl;
		b1->executeForm(*f1);
		b1->executeForm(*f2);
		b1->executeForm(*f3);
		
		std::cout << "Bureaucrat 2:" << std::endl;
		b2->executeForm(*f1);
		b2->executeForm(*f2);
		b2->executeForm(*f3);
		
		std::cout << "Bureaucrat 3:" << std::endl;
		b3->executeForm(*f1);
		b3->executeForm(*f2);
		b3->executeForm(*f3);

		delete b1;
		delete b2;
		delete b3;
		delete f1;
		delete f2;
		delete f3;
	}
	return 0;
}