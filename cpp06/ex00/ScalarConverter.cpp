/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:03:37 by ncampbel          #+#    #+#             */
/*   Updated: 2025/04/05 18:51:46 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return *this;
}

ScalarConverter::~ScalarConverter(){
}

// static is_char
static void is_char(char c)
{
	std::cout << BLD_BLUE << "char: " << RESET << c << std::endl;
	std::cout << BLD_CYAN << "int: " << RESET << static_cast<int>(c) << std::endl;
	std::cout << BLD_MAGENTA << "float: " << RESET << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << BLD_YELLOW << "double: " << RESET << static_cast<double>(c) << ".0" << std::endl;
}

// static is_int
static void is_int(long nb)
{
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
	{
		std::cout << BLK_RED << "INT OVERFLOR OR UNDERFLOW DETECTED!" << RESET << std::endl;
		return ;
	}
	if (nb < 0 || nb > 127 || !std::isprint(nb))
		std::cout << BLD_BLUE <<  "char: " << RESET << "Non displayable" << std::endl;
	else
		std::cout << BLD_BLUE << "char: " << RESET << static_cast<char>(nb) << std::endl;
	std::cout << BLD_CYAN << "int: " << RESET << static_cast<int>(nb) << std::endl;
	std::cout << BLD_MAGENTA << "float: " << RESET << static_cast<float>(nb) << ".0f" << std::endl;
	std::cout << BLD_YELLOW << "double: " << static_cast<double>(nb) << RESET <<".0" << std::endl;
}

// static is_nan
static void is_nan(std::string nan)
{
	std::cout << BLD_BLUE << "char: " << RESET << "impossible" << std::endl;
	std::cout << BLD_CYAN << "int: " << RESET << "impossible" << std::endl;
	if (nan == "nanf")
	{
		float f = std::numeric_limits<float>::quiet_NaN();
		std::cout << BLD_MAGENTA << "float: " << RESET << f << "f" << std::endl;
		std::cout << BLD_YELLOW << "double: " << RESET << static_cast <double> (f) << std::endl;
	}
	else
	{
		double d = std::numeric_limits<double>::quiet_NaN();
		std::cout << BLD_MAGENTA << "float: " << RESET << static_cast <float> (d) << "f" << std::endl;
		std::cout << BLD_YELLOW << "double: " << RESET << d << std::endl;
	}
}

// statis is_inf
static void is_inf(std::string inf)
{
	std::cout << BLD_BLUE << "char: " << RESET << "impossible" << std::endl;
	std::cout << BLD_CYAN << "int: " << RESET << "impossible" << std::endl;
	if (inf.compare(1, 4, "inff") == 0)
	{
		float f = std::numeric_limits<float>::infinity();
		if (inf[0] == '-')
			f = -f;
		std::cout << BLD_MAGENTA << "float: " << RESET << f << "f" << std::endl;
		std::cout << BLD_YELLOW << "double: " << RESET << static_cast <double> (f) << std::endl;
	}
	else
	{
		double d = std::numeric_limits<double>::infinity();
		if (inf[0] == '-')
			d = -d;
		std::cout << BLD_MAGENTA << "float: " << RESET << static_cast <float> (d) << "f" << std::endl;
		std::cout << BLD_YELLOW << "double: " << RESET << d << std::endl;
	}
}


// static is_float
static void	is_float(float f)
{
	if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
	{
		std::cerr << "FLOAT OVERFLOR OR UNDERFLOW DETECTED!" << std::endl;
		return ;
	}
	if (f < 0 || f > 127 || !std::isprint(f))
		std::cout << BLD_BLUE << "char: " << RESET << "Non displayable" << std::endl;
	else
		std::cout << BLD_BLUE << "char: '" << RESET << static_cast<char>(f) << "'" << std::endl;
	std::cout << BLD_CYAN << "int: " << RESET << static_cast<int>(f) << std::endl;
	if (f - static_cast<int>(f) == 0){
		std::cout << BLD_MAGENTA << "float: " << RESET << f << ".0f" << std::endl;
    	std::cout << BLD_YELLOW << "double: " << RESET << static_cast<double>(f) << ".0" << std::endl;}
	else{
    	std::cout << BLD_MAGENTA << "float: " << RESET << f << "f" << std::endl;
    	std::cout << BLD_YELLOW << "double: " << RESET << static_cast<double>(f) << std::endl;}
}

// static is_double
static void	is_double(double d)
{
	if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
	{
		std::cerr << "DOUBLE OVERFLOR OR UNDERFLOW DETECTED!" << std::endl;
		return ;
	}
	if (d < 0 || d > 127 || !std::isprint(d))
		std::cout << BLD_BLUE << "char: " << RESET << "Non displayable" << std::endl;
	else
		std::cout << BLD_BLUE << "char: '" << RESET << static_cast<char>(d) << "'" << std::endl;
	std::cout << BLD_CYAN << "int: " << RESET << static_cast<int>(d) << std::endl;
	if (d - static_cast<int>(d) == 0){
		std::cout << BLD_MAGENTA << "float: " << RESET << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << BLD_YELLOW << "double: " << RESET << d << ".0" << std::endl;}
	else{
		std::cout << BLD_MAGENTA << "float: " << RESET << static_cast<float>(d) << "f" << std::endl;
		std::cout << BLD_YELLOW << "double: " << RESET << d << std::endl;}
}


void ScalarConverter::convert(std::string str)
{
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		is_char(str[0]);
	else if (str == "nan" || str == "nanf")
		is_nan(str);
	else if (str == "inf" || str == "inff" || str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff")
		is_inf(str);
	else if (str.find_first_of("-+") != str.find_last_of("-+"))
		return ;
	else if (str.find_first_not_of("-+0123456789") == std::string::npos)
		is_int(std::strtol(str.c_str(), NULL, 10));
	else if (str.find_first_not_of("-+0123456789."))
	{
		if (str.find_first_of(".") != str.find_last_of(".") ||
			str.find_first_of(".") == 0 ||
			str[str.find_first_of(".") + 1] == '\0')
			return ;
		is_double(strtod(str.c_str(), NULL));
	}
	else if (str.find_first_not_of("-+0123456789.f") == std::string::npos)
	{
		if (str.find_first_of("f") != str.find_last_of("f") ||
			str.find_first_of("f") - str.find_first_of(".") == 1 ||
			str.find_first_of(".") != str.find_last_of(".") ||
			str.find_first_of(".") == 0 ||
			str[str.find_first_of("f") + 1] != '\0')
			return ;
		is_float(strtof(str.c_str(), NULL));
	}
}
