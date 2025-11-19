/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:03:53 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/19 16:38:28 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main(int ac, char **av)
{
	Data *data;

	if (ac != 2)
	{
		std::cout << "Usage: ./serialize [int]" << std::endl;
		return (1);
	}
	data = new Data;
	data->n = std::strtol(av[1], NULL, 10);
	std::cout << BLD_GREEN << "\n\n### TESTING SERIALIZATION ###" << RESET << std::endl;
	std::cout << BLD_CYAN << "Data->ptr: " << UND_MAGENTA << data << RESET << std::endl;
	std::cout << BLD_BLUE << "Data->n: " << UND_MAGENTA << data->n << RESET << std::endl;
	std::cout << BLD_YELLOW << "### SERIALIZING ###" << RESET << std::endl;
	uintptr_t raw = Serialization::serialize(data);
	std::cout << BLD_WHITE << "Raw: " << UND_MAGENTA << raw << RESET << std::endl;
	std::cout << BLD_YELLOW << "### DESERIALIZING ###" << RESET << std::endl;
	data = Serialization::deserialize(raw);
	Data *newData = Serialization::deserialize(raw);
	std::cout << BLD_CYAN << "Data->ptr: " << UND_MAGENTA << data << RESET << std::endl;
	std::cout << BLD_BLUE << "Data->n: " << UND_MAGENTA << data->n << RESET << std::endl;
	std::cout << BLD_CYAN << "newData->ptr: " << UND_MAGENTA << newData << RESET << std::endl;
	std::cout << BLD_BLUE << "newData->n: " << UND_MAGENTA << newData->n << RESET << std::endl;
	delete data;
}