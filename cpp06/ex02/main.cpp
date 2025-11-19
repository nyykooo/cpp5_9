/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:09:38 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/19 17:26:26 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

Base *generate(void)
{
	std::srand(std::time(0));

	int random = std::rand() % 3;
	
	switch (random)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		break;
	}
	return (0);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) // se retornar null nao eh um pointer de A
		std::cout << BLD_MAGENTA << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << BLD_MAGENTA << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << BLD_MAGENTA << "C" << RESET << std::endl;
	else
		std::cout << BLK_RED << "Unknown" << RESET << std::endl;
}

void identify(Base& p)
{
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << BLD_MAGENTA << "A" << RESET << std::endl;}
	catch (std::exception &e)
	{
		try{
			(void)dynamic_cast<B&>(p);
			std::cout << BLD_MAGENTA << "B" << RESET << std::endl;}
		catch (std::exception &e)
		{
			try{
				(void)dynamic_cast<C&>(p);
				std::cout << BLD_MAGENTA << "C" << RESET << std::endl;}
			catch (std::exception &e)
			{
				std::cout << BLK_RED << "Unknown" << RESET << std::endl;
			}
		}
	}
}

int main()
{
	Base *base = generate();
	std::cout << BLD_GREEN << "\n### IDENTIFYING THROUGH POINTER ###" << RESET << std::endl;
	identify(base);
	std::cout << BLD_GREEN << "\n\n### IDENTIFYING THROUGH REFERENCE ###" << RESET << std::endl;
	identify(*base);
	delete base;
	return (0);
}