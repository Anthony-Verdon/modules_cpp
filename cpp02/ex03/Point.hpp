/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:06:24 by averdon           #+#    #+#             */
/*   Updated: 2023/03/01 18:22:45 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	 public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &instance);
		float getX(void)const;
		float getY(void)const;
		~Point(void);
		
		Point& 	operator = (const Point &instance);

	 private:
		const float _x;
		const float _y;
		
};

bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif
