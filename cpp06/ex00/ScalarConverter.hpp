/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:03:42 by ncampbel          #+#    #+#             */
/*   Updated: 2025/01/31 17:51:06 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cstdlib>
# include <iostream>
# include <string>
# include <sstream>
# include <limits>
# include <iomanip>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		virtual ~ScalarConverter() = 0;
		ScalarConverter& operator=(const ScalarConverter& copy);

		static void convert(std::string string);
};

#endif