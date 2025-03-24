/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:57:40 by ncampbel          #+#    #+#             */
/*   Updated: 2025/03/20 19:51:24 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <list>
# include <limits>
# include <algorithm>
# include <ctime>

class BitcoinExchange
{
	private:
		std::tm		_date;
		std::string _dateString;
		std::string	_valueString;
		float		_value;
		std::string _error;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string line);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		std::string			checkDate(std::string date) const;
		std::string			checkValue(std::string valueString) const;

		void				setDate(std::string date);
		void				setValue(std::string value);
		void				setValueString(std::string valueString);
		void				setError(std::string error);

		std::tm				getDate() const;
		float				getValue() const;
		std::string			getError() const;
		std::string			getDateString() const;
};

#endif