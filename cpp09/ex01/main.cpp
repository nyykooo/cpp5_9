/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:33:40 by ncampbel          #+#    #+#             */
/*   Updated: 2025/03/25 19:18:37 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./rpn \"[valid RPN expression]\"" << std::endl;
		return 1;
	}
	try{
		RPN rpn(argv[1]);

		std::cout << rpn.getResult() << std::endl;	
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}