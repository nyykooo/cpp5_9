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

// map was choosen because it stores data in sorted order, allowing for greater efficiency and ease use for this exercise
class BitcoinExchange
{
	private:
		std::map<std::string, float>	_db;

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