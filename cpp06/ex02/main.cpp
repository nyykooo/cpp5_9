/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:09:38 by ncampbel          #+#    #+#             */
/*   Updated: 2025/02/04 21:02:32 by ncampbel         ###   ########.fr       */
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
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;}
	catch (std::exception &e)
	{
		try{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;}
		catch (std::exception &e)
		{
			try{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;}
			catch (std::exception &e)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}