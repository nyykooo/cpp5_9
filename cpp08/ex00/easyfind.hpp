/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:03:10 by ncampbel          #+#    #+#             */
/*   Updated: 2025/11/25 18:40:59 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <list>
# include <deque>
# include "macros.hpp"

template <typename T>
int easyfind(T &container, int n);

# include "easyfind.tpp"

#endif