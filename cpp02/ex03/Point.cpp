/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:05:41 by averdon           #+#    #+#             */
/*   Updated: 2023/03/01 18:22:24 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &instance) : _x(instance._x), _y(instance._y)
{
}

Point::~Point(void)
{
}

Point& Point::operator = (const Point &instance)
{
	this->~Point();
	new(this) Point(instance._x, instance._y);
	return (*this);
}

float Point::getX(void)const
{
	return (this->_x);
}

float Point::getY(void)const
{
	return (this->_y);
}
