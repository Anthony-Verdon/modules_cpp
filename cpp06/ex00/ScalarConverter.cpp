/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:53:48 by averdon           #+#    #+#             */
/*   Updated: 2023/03/14 17:49:27 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cerrno>
#include <limits.h>
#include <cstdlib>

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	*this = copy;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &copy){
	if (&copy != this)
	{

	}
	return (*this);
}

bool	is_digit(std::string literal)
{
	if (literal[0] != '-' && literal[0] != '+' && !(literal[0] >= '0' && literal[0] <= '9'))
		return (false);
	for (int i = 1; literal[i]; i++)
	{
		if (literal[i] < '0' || literal[i] > '9')
			return (false);
	}
	return (true);
}

int	ScalarConverter::findType(std::string literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (FLOAT);
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (DOUBLE);
	else if (literal.length() == 1 && (literal[0] < '0' || literal[0] > '9'))
		return (CHAR);
	else if (is_digit(literal) == true)
		return (INT);

	bool findF = false;
	bool findPoint = false;
	for (size_t i = 0; literal[i]; i++)
	{
		if (literal[i] == 'f')
		{
			if (findF == true || i + 1 != literal.length())
				return (UNDEFINED);
			findF = true;
		}
		else if (literal[i] == '.')
		{
			if (findPoint == true)
				return (UNDEFINED);
			findPoint = true;
		}
		else if (literal[i] < '0' || literal[i] > '9')
			return (UNDEFINED);

	}
	if (findF)
		return (FLOAT);
	else
		return (DOUBLE);
}

void	ScalarConverter::print_conversions(int type, std::string literal)
{
	char 	number_char;
	long	number_int;
	float	number_float;
	double	number_double;

	if (type == CHAR)
	{
		number_char = literal.c_str()[0];
		if (number_char < 32 || number_char >= 127)
			std::cout << "char: non displayable\n";
		else
			std::cout << "char: " << number_char <<"\n";
		std::cout << "int: " << static_cast<int>(number_char) <<"\n";
		std::cout << "float: "  << static_cast<float>(number_char) << ".0f" << "\n";
		std::cout << "double: " << static_cast<double>(number_char) << ".0" << "\n";
	}
	else if (type == INT)
	{
		number_int = std::strtol(literal.c_str(), NULL, 10);
		if (number_int < INT_MIN || number_int > INT_MAX)
		{
			std::cout << "int overflow : conversions are impossible\n";
			return ;
		}
		if (number_int < 32 || number_int >= 127)
			std::cout << "char: non displayable\n";
		else
			std::cout << "char: " << static_cast<char>(number_int) <<"\n";
		std::cout << "int: " << number_int <<"\n";
		std::cout << "float: "  << static_cast<float>(number_int) << ".0f\n";
		std::cout << "double: " << static_cast<double>(number_int) << ".0\n";
	}
	else if (type == FLOAT)
	{
		errno = 0;
		number_float = std::strtof(literal.c_str(), NULL);
		if (errno != 0)
		{
			std::cout << "float overflow : conversions are impossible\n";
			return ;
		}
		if (number_float < 32 || number_float >= 127)
			std::cout << "char: non displayable\n";
		else if (literal == "nanf" || literal.find("inff") != std::string::npos)
			std::cout << "char: impossible\n";
		else
			std::cout << "char: " << static_cast<char>(number_float) <<"\n";
		if (literal == "nanf" || literal.find("inff") != std::string::npos
			|| static_cast<long>(number_float) < INT_MIN
			|| static_cast<long>(number_float) > INT_MAX)
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(number_float) <<"\n";
		std::cout << "float: "  << number_float << "f\n";
		std::cout << "double: " << static_cast<double>(number_float) << "\n";
	}
	else if (type == DOUBLE)
	{
		errno = 0;
		number_double = std::strtod(literal.c_str(), NULL);
		if (errno != 0)
		{
			std::cout << "double overflow : conversions are impossible\n";
			return ;
		}
		if (number_double < 32 || number_double >= 127)
			std::cout << "char: non displayable\n";
		else if (literal == "nan" || literal.find("inf") != std::string::npos)
			std::cout << "char: impossible\n";
		else
			std::cout << "char: " << static_cast<char>(number_double) <<"\n";
		if (literal == "nanf" || literal.find("inff") != std::string::npos
			|| static_cast<long>(number_double) < INT_MIN
			|| static_cast<long>(number_double) > INT_MAX)
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(number_double) <<"\n";
		std::cout << "float: "  << static_cast<float>(number_double) << "f\n";
		std::cout << "double: " << number_double << "\n";
	}
}

void	ScalarConverter::convert(std::string literal)
{
	int	type;

	type = findType(literal);
	if (type != UNDEFINED)
		print_conversions(type, literal);
	else
		std::cerr << "conversions are impossible\n";
}
