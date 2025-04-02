/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:55:00 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/02 19:51:16 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
	{
		Bureaucrat *bureaucrat = NULL;
		Form *form = NULL;
		
		std::cout << BLD_GREEN << "\n\n### TESTING SIGNFORM ###" << RESET << std::endl; 
		try {
			bureaucrat = new Bureaucrat("Nico", 99);
			form = new Form("ABC", 100, 100, false);

			std::cout << *bureaucrat;
			std::cout << *form;
			bureaucrat->signForm(*form);
			std::cout << *form;
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete bureaucrat;
		delete form;
	}
	{
		Bureaucrat *bureaucrat = NULL;
		Form *form = NULL;
		
		std::cout << BLD_GREEN << "\n\n ### TESTING GRADELOW IN SIGNFORM ###" << RESET << std::endl;
		try {
			bureaucrat = new Bureaucrat("Nico", 101);
			form = new Form("DEF", 100, 100, false);

			std::cout << *bureaucrat;
			std::cout << *form;
			bureaucrat->signForm(*form);
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete bureaucrat;
		delete form;
	}
	{
		Form *form1 = NULL;
		
		std::cout << BLD_GREEN << "\n\n ### TESTING CREATING A WRONG RATE FORM ###" << RESET << std::endl;
		try {
			form1 = new Form("DEF", 151, 10, false);
			
			std::cout << *form1;
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete form1;
		Form *form2 = NULL;
		try {
			form2 = new Form("DEF", 15, 1000, false);
			
			std::cout << *form2;
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete form2;
		Form *form3 = NULL;
		try {
			form3 = new Form("DEF", 15, 100, false);
			
			std::cout << *form3;
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete form3;
		Form *form4 = NULL;
		try {
			form4 = new Form("DEF", 100, 0, false);
			
			std::cout << *form4;
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete form4;
		Form *form5 = NULL;
		try {
			form5 = new Form("DEF", 0, 100, false);
			
			std::cout << *form5;
		} catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete form5;
	}
	return 0;
}