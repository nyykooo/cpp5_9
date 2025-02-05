/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:03:53 by ncampbel          #+#    #+#             */
/*   Updated: 2025/02/04 19:59:33 by ncampbel         ###   ########.fr       */
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
	std::cout << "Data->n: " << data->n << std::endl;
	std::cout << "Data->ptr: " << data << std::endl;
	std::cout << "--------------" << std::endl;
	uintptr_t raw = Serialization::serialize(data);
	std::cout << "Raw: " << raw << std::endl;
	std::cout << "--------------" << std::endl;
	Data *newData = Serialization::deserialize(raw);
	std::cout << "NewData->n: " << newData->n << std::endl;
	std::cout << "NewData->ptr: " << newData << std::endl;
}