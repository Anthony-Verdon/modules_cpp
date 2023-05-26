/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:45:02 by averdon           #+#    #+#             */
/*   Updated: 2023/03/16 13:19:52 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>

void	swap(T &x, T &y)
{
	T temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T>

const	T & min(const T & x, const T & y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

template <typename T>

const T &	max(const T & x,const T & y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
#endif
