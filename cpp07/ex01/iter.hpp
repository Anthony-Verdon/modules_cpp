/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:21:01 by averdon           #+#    #+#             */
/*   Updated: 2023/03/16 13:42:36 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename F>

void	iter(T & array, size_t size, F function)
{
	if (size < 0 || size > sizeof(array) / sizeof(array[0]))
	{
		std::cerr << "size invalid\n";
		return ;
	}
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}
#endif
