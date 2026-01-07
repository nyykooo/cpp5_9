#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <limits>
# include <algorithm>
# include <ctime>

#include "macros.hpp"

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_db; // o map armazena os dados de forma sorted automaticamente, permitindo maior eficiencia e uso facilitado para esse exercicio

	public:
		BitcoinExchange();
		BitcoinExchange(std::string dataBase);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		void storeDb(std::string dbName);

		void run(std::string fileName);

		bool parseDate(std::string date);
		bool parseValue(float value);

		void printSuccess(std::string date, float value);
		void printError(std::string message);
};

#endif