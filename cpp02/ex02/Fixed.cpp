/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:42:31 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 14:11:55 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_rawBits = 0;
}

Fixed::Fixed(const Fixed &instance)
{
	this->_rawBits = instance._rawBits;
}

Fixed::Fixed(const int value)
{
	this->_rawBits = value * (1 << this->_nb_bits_fract_part);
}

Fixed::Fixed(const float value)
{
	this->_rawBits = roundf(value * (1 << this->_nb_bits_fract_part));
}

Fixed& Fixed::operator = (const Fixed& instance)
{
	this->_rawBits = instance._rawBits;
	return (*this);
}

bool Fixed::operator > (const Fixed& instance)
{
	if (this->_rawBits > instance._rawBits)
		return (true);
	else
		return (false);
}

bool Fixed::operator < (const Fixed& instance)
{
	if (this->_rawBits < instance._rawBits)
		return (true);
	else
		return (false);
}

bool Fixed::operator >= (const Fixed& instance)
{
	if (this->_rawBits >= instance._rawBits)
		return (true);
	else
		return (false);
}

bool Fixed::operator <= (const Fixed& instance)
{
	if (this->_rawBits <= instance._rawBits)
		return (true);
	else
		return (false);
}

bool Fixed::operator == (const Fixed& instance)
{
	if (this->_rawBits == instance._rawBits)
		return (true);
	else
		return (false);
}

bool Fixed::operator != (const Fixed& instance)
{
	if (this->_rawBits != instance._rawBits)
		return (true);
	else
		return (false);
}

//ex : ++a
Fixed& Fixed::operator ++(void)
{
	this->_rawBits++;
	return (*this);
}

//ex : a++
Fixed Fixed::operator ++(int)
{
	Fixed temp;
	
	temp = *this;
	this->_rawBits++;
	return (temp);
}

Fixed& Fixed::operator --(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator --(int)
{
	Fixed temp;
	
	temp = *this;
	this->_rawBits--;
	return (temp);
}

Fixed Fixed::operator + (const Fixed &instance)
{
	return (Fixed(this->toFloat() + instance.toFloat()));
}

Fixed Fixed::operator - (const Fixed &instance)
{
	return (Fixed(this->toFloat() - instance.toFloat()));
}

Fixed Fixed::operator * (const Fixed &instance)
{
	return (Fixed(this->toFloat() * instance.toFloat()));
}

Fixed Fixed::operator / (const Fixed &instance)
{
	return (Fixed(this->toFloat() / instance.toFloat()));
}

std::ostream& operator << (std::ostream& os, const Fixed& instance)
{
	os << instance.toFloat();
	return (os);
}

const Fixed& Fixed::min (const Fixed& nb1, const Fixed& nb2)
{
	if (nb1._rawBits < nb2._rawBits)
		return (nb1);
	else
		return (nb2);
}

const Fixed& Fixed::max (const Fixed& nb1, const Fixed& nb2)
{
	if (nb1._rawBits > nb2._rawBits)
		return (nb1);
	else
		return (nb2);
}

Fixed& Fixed::min (Fixed& nb1, Fixed& nb2)
{
	if (nb1 < nb2)
		return (nb1);
	else
		return (nb2);
}

Fixed& Fixed::max (Fixed& nb1, Fixed& nb2)
{
	if (nb1 > nb2)
		return (nb1);
	else
		return (nb2);
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void)const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(const int raw)
{
	this->_rawBits = raw;
}

int	Fixed::toInt(void) const
{
	return ((this->_rawBits / (1 << this->_nb_bits_fract_part)));
}

float	Fixed::toFloat(void) const
{
	return (((float)this->_rawBits / (float)(1 << this->_nb_bits_fract_part)));
}
