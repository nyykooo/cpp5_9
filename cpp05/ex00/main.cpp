/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:55:00 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/22 14:09:22 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat *bureaucrat = new Bureaucrat("Nico", 99);
		Bureaucrat *bureaucrat2 = new Bureaucrat("Top", 1);
		Bureaucrat *bureaucrat3 = new Bureaucrat("Bottom", 150);

		try
		{
			bureaucrat->incrementGrade();
			bureaucrat3->incrementGrade();
			bureaucrat2->incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete bureaucrat;
		delete bureaucrat2;
		delete bureaucrat3;
	}

	{
		Bureaucrat *bureaucrat = new Bureaucrat("Nico", 99);
		Bureaucrat *bureaucrat2 = new Bureaucrat("Top", 1);
		Bureaucrat *bureaucrat3 = new Bureaucrat("Bottom", 150);

		try
		{
			bureaucrat->decrementGrade();
			bureaucrat2->decrementGrade();
			bureaucrat3->decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete bureaucrat;
		delete bureaucrat2;
		delete bureaucrat3;
	}
	return 0;
}