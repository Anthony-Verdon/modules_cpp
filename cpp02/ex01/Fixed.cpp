/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:42:31 by averdon           #+#    #+#             */
/*   Updated: 2023/03/01 13:21:34 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <ostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->_rawBits = 0;
}

Fixed::Fixed(const Fixed &instance)
{
	std::cout << "Copy constructor called\n";
	this->_rawBits = instance._rawBits;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	this->_rawBits = value * (1 << this->_nb_bits_fract_part);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	this->_rawBits = roundf(value * (1 << this->_nb_bits_fract_part));
}

Fixed& Fixed::operator = (const Fixed& instance)
{
	std::cout << "Copy assignement operator called\n";
	this->_rawBits = instance._rawBits;
	return (*this);
}

std::ostream& operator << (std::ostream& os, const Fixed& instance)
{
	os << instance.toFloat();
	return (os);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void)const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	this->_rawBits = raw;
}

int	Fixed::toInt(void) const
{
	return ((this->_rawBits / (1 << this->_nb_bits_fract_part)));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits /(float)(1 << this->_nb_bits_fract_part));
}
