/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:30:02 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/14 18:15:34 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include <cstdlib>
# include "macros.hpp"

struct Data
{
	int n;
};

class Serialization
{
	public:
		Serialization();
		Serialization(const Serialization& copy);
		Serialization & operator=(const Serialization& copy);
		virtual ~Serialization() = 0;

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif