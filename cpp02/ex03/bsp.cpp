/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:05:50 by averdon           #+#    #+#             */
/*   Updated: 2023/03/01 18:32:06 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

Fixed	calculate_area(Point const i, Point const j, Point const k)
{
	Fixed	area;
	area = std::abs(0.5f * (i.getX() * (j.getY() - k.getY()) + j.getX() * (k.getY() - i.getY()) + k.getX() * (i.getY() - j.getY())));
	return (area);
}
//if area of ABP + BCP + ACP = area of ABC, then P is in ABC
bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed areaABP = calculate_area(a, b, p);
	Fixed areaBCP = calculate_area(b, c, p);
	Fixed areaACP = calculate_area(a, c, p);
	if (areaABP + areaBCP + areaACP == calculate_area(a, b, c)
			&& areaABP != 0 && areaBCP != 0 && areaACP != 0)
		return (true);
	else
		return (false);
}
