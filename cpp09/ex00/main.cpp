/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:57:23 by ncampbel          #+#    #+#             */
/*   Updated: 2025/03/24 20:03:36 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static std::list<BitcoinExchange> ft_getInputValues(const char *file)
{
	std::list<BitcoinExchange> bitcoinList;
	
	std::ifstream	fileName(file);
	if (!fileName.is_open())
	{
		std::cout << "File could not be opened." << std::endl;
		return(bitcoinList);
	}

	std::string	line;
	std::getline(fileName, line); // skips the first line (header)
	while (std::getline(fileName, line))
	{
		if (line.find("|") != std::string::npos)
		{
			line.erase(line.find("|") - 1, 1);
			line.erase(line.find("|") + 1, 1);
			line[line.find("|")] = ',';
		}
		BitcoinExchange bitLine(line);
		bitcoinList.push_back(bitLine); 
	}

	fileName.close();

	return (bitcoinList);
}

bool compareDates(std::tm date1, std::tm date2)
{
	if (date1.tm_year == date2.tm_year && date1.tm_mon == date2.tm_mon && date1.tm_mday == date2.tm_mday)
		return (true);
	if (date1.tm_year == date2.tm_year && date1.tm_mon == date2.tm_mon && date1.tm_mday < date2.tm_mday)
		return (true);
	if (date1.tm_year == date2.tm_year && date1.tm_mon < date2.tm_mon)
		return (true);
	if (date1.tm_year < date2.tm_year)
		return (true);
	return (false);
}

int main(int ac, char **av)
{
	std::list<BitcoinExchange> input;
	std::list<BitcoinExchange> dataBase;
	const char *dataBaseFile = "data.csv";
	
	if (ac == 1)
	{
		std::cout << "No input values provided." << std::endl;
		return(1);
	}

	if (ac > 2)
	{
		std::cout << "Too many arguments." << std::endl;
		return(1);
	}

	input = ft_getInputValues(av[1]);
	dataBase = ft_getInputValues(dataBaseFile);

	for (std::list<BitcoinExchange>::iterator it = input.begin(); it != input.end(); it++)
	{
		for(std::list<BitcoinExchange>::iterator it2 = dataBase.begin(); it2 != dataBase.end(); it2++)
		{
			if (compareDates(it->getDate(), it2->getDate()) == true)
			{
				if (it->getError().compare("ok") != 0)
					std::cout << it->getError() << std::endl;
				else
					std::cout << it->getDateString() << " => " << it->getValue() << " = " << (it->getValue() * it2->getValue()) << std::endl;
				break;
			}
		}
	}
	
	return (0);
}
