/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:55:00 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/02 19:38:51 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat *bureaucrat = NULL;
		Bureaucrat *bureaucrat2 = NULL;
		Bureaucrat *bureaucrat3 = NULL;

		try
		{
			std::cout << BLD_GREEN << "\n\nTESTING INCREMENT GRADE" << RESET << std::endl;
			bureaucrat = new Bureaucrat("Nico", 99);
			bureaucrat2 = new Bureaucrat("Top", 1);
			bureaucrat3 = new Bureaucrat("Bottom", 150);


			std::cout << BLD_BLUE << bureaucrat->getName() << RESET << ": " << BLD_MAGENTA << bureaucrat->getGrade() << RESET << std::endl;
			std::cout << BLD_BLUE << bureaucrat2->getName() << RESET << ": " << BLD_MAGENTA << bureaucrat2->getGrade() << RESET << std::endl;
			std::cout << BLD_BLUE << bureaucrat3->getName() << RESET << ": " << BLD_MAGENTA << bureaucrat3->getGrade() << RESET << std::endl;
			
			bureaucrat->incrementGrade();
			bureaucrat3->incrementGrade();
			bureaucrat2->incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete bureaucrat;
		delete bureaucrat2;
		delete bureaucrat3;
	}

	{
		Bureaucrat *bureaucrat = NULL;
		Bureaucrat *bureaucrat2 = NULL;
		Bureaucrat *bureaucrat3 = NULL;

		try
		{
			std::cout << BLD_GREEN << "\n\nTESTING DECREMENT GRADE" << RESET << std::endl;
			bureaucrat = new Bureaucrat("Nico", 99);
			bureaucrat2 = new Bureaucrat("Top", 1);
			bureaucrat3 = new Bureaucrat("Bottom", 150);
			
			std::cout << BLD_BLUE << bureaucrat->getName() << RESET << ": " << BLD_MAGENTA << bureaucrat->getGrade() << RESET << std::endl;
			std::cout << BLD_BLUE << bureaucrat2->getName() << RESET << ": " << BLD_MAGENTA << bureaucrat2->getGrade() << RESET << std::endl;
			std::cout << BLD_BLUE << bureaucrat3->getName() << RESET << ": " << BLD_MAGENTA << bureaucrat3->getGrade() << RESET << std::endl;

			bureaucrat->decrementGrade();
			bureaucrat2->decrementGrade();
			bureaucrat3->decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete bureaucrat;
		delete bureaucrat2;
		delete bureaucrat3;
	}
	{
		Bureaucrat *fancy = NULL;

		try
		{
			std::cout << BLD_GREEN << "\n\nTESTING GRADE TOO HIGH EXCEPTION" << RESET << std::endl;
			fancy = new Bureaucrat("Fancy", 0);

			fancy->incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete fancy;
	}
	{
		Bureaucrat *dumbo = NULL;
		
		try
		{
			std::cout << BLD_GREEN << "\n\nTESTING GRADE TOO LOW EXCEPTION" << RESET << std::endl;
			dumbo = new Bureaucrat("Dumbo", 151);

			dumbo->decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << BLK_RED << e.what() << RESET << std::endl;
		}
		delete dumbo;
	}
	{
		std::cout << BLD_GREEN << "\n\nTESTING OUTPUT OVERLOAD" << RESET << std::endl;


		//std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &fixed);
		/* std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat &bureaucrat)
		{
			outputStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
			return outputStream;	
		} */


		Bureaucrat *bureaucrat = new Bureaucrat("Nico", 99);
		std::cout << *bureaucrat;
		delete bureaucrat;
	}
	return 0;
}