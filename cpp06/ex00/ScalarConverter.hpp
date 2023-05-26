/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:53:51 by averdon           #+#    #+#             */
/*   Updated: 2023/03/13 15:33:40 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>

# define DOUBLE 1
# define FLOAT 2
# define CHAR 3
# define INT 4
# define UNDEFINED 5

class ScalarConverter
{
	 public:
		static void	convert(std::string literal);
		static int	findType(std::string literal);
		static void	print_conversions(int type, std::string literal);
	 private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter (const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter&);
};

#endif
