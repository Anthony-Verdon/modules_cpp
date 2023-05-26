/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:43:54 by averdon           #+#    #+#             */
/*   Updated: 2023/03/16 16:19:38 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
template <typename T>

class Array
{
	 public:
		Array();
		Array(unsigned int n);
		~Array();
		Array (const Array &copy);
		Array &operator=(const Array&);
		T &operator[](unsigned int index);

		class BadIndex : public std::exception
		{
			const char *what(void) const throw();
		};

		unsigned int	size(void) const;
	 private:
		T 	*_array;
		unsigned int _size;
		
};

#endif
