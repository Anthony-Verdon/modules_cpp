/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:09 by averdon           #+#    #+#             */
/*   Updated: 2023/03/01 13:06:58 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "-----------------------------------------\n";
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	a = Fixed(10);
	std::cout << "addition: " << a << " + " << b << " = " << a + b << std::endl;
	std::cout << "soustraction: "<< a << " - " << b << " = "  << a - b << std::endl;
	std::cout << "multiplication: "<< a << " * " << b << " = "  << a * b << std::endl;
	std::cout << "division: "<< a << " / " << b << " = "  << a / b << std::endl;
	return 0;
}
