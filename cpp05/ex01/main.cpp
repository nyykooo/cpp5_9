/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:55:00 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/24 16:00:42 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
	{
		Bureaucrat *bureaucrat = new Bureaucrat("Nico", 99);
		Form *form = new Form("ABC", 100, 100, false);

		std::cout << *bureaucrat;
		std::cout << *form;
		form->beSigned(*bureaucrat);
	}
	{
		Bureaucrat *bureaucrat = new Bureaucrat("Nico", 101);
		Form *form = new Form("DEF", 100, 100, false);

		std::cout << *bureaucrat;
		std::cout << *form;
		form->beSigned(*bureaucrat);
	}
	return 0;
}