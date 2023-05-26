/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:42:31 by averdon           #+#    #+#             */
/*   Updated: 2023/02/27 15:16:28 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->_rawBits = 0;
}

Fixed::Fixed(Fixed &instance)
{
	std::cout << "Copy constructor called\n";
	this->_rawBits = instance._rawBits;
}

Fixed& Fixed::operator = (const Fixed& instance)
{
	std::cout << "Copy assignement operator called\n";
	this->_rawBits = instance._rawBits;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called\n";
	return (this->_rawBits);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	this->_rawBits = raw;
}
