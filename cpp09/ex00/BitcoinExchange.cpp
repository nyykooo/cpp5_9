/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:09:07 by ncampbel          #+#    #+#             */
/*   Updated: 2025/03/24 19:47:17 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string line)
{
	setDate(line.substr(0, line.find(",")));
	if (line.find(",") != std::string::npos)
	{
		setValueString(line.substr(line.find(",") + 1, line.size()));
		setValue(this->_valueString);
	}
	else
		this->_valueString = "";
	setError(checkDate(this->_dateString));
	setError(checkValue(this->_valueString));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	this->_date = copy._date;
	this->_dateString = copy._dateString;
	this->_valueString = copy._valueString;
	this->_value = copy._value;
	this->_error = copy._error;
	return (*this);
}

// ### CHECKERS ###
std::string BitcoinExchange::checkDate(std::string date) const
{
	std::string year = date.substr(0, date.find_first_of("-"));
	std::istringstream month(date.substr(date.find_first_of("-") + 1, 3));
	std::istringstream day(date.substr(date.find_last_of("-") + 1, 3));

	if (year.size() != 4)
		return ("Error: bad year.");

	int num;
	month >> num;
	if (num < 1 || num > 12)
		return ("Error: bad month.");
	
	day >> num;
	if (num < 1 || num > 31)
		return ("Error: bad day.");
	
	return("ok");
}

std::string BitcoinExchange::checkValue(std::string valueString) const
{
	std::istringstream value(valueString);
	double num;

	if (valueString == "")
		return ("Error: bad input => " + this->_dateString);

	value >> num;
	if (num < 0)
		return ("Error: not a positive number.");
	
	if (num > std::numeric_limits<int>::max())
		return ("Error: too large a number.");

	return ("ok");
}


// ### SETTERS ###
void BitcoinExchange::setDate(std::string date)
{
	std::istringstream dateStream(date);
	this->_dateString = date;
	char dash1;
	char dash2;
	dateStream >> this->_date.tm_year >> dash1 >> this->_date.tm_mon >> dash2 >> this->_date.tm_mday;
	if (dash1 != '-' || dash2 != '-')
	{
		this->_error = "Error: bad date format.";
		return ;
	}
}

void BitcoinExchange::setValue(std::string value)
{
	std::istringstream valueStream(value);
	valueStream >> this->_value;
}

void BitcoinExchange::setValueString(std::string valueString)
{
	this->_valueString = valueString;
}

void BitcoinExchange::setError(std::string error)
{
	this->_error = error;
}

// ### GETTERS ###
std::tm BitcoinExchange::getDate() const
{
	return (this->_date);
}

std::string BitcoinExchange::getDateString() const
{
	return (this->_dateString);
}

float BitcoinExchange::getValue() const
{
	return (this->_value);
}

std::string BitcoinExchange::getError() const
{
	return (this->_error);
}