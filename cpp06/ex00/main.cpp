/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:03:53 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/05 17:16:46 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << BLK_RED << "Usage: ./convert [value]" << RESET << std::endl;
		return 1;
	}
	ScalarConverter::convert(static_cast<std::string>(av[1]));
	return 0;
}