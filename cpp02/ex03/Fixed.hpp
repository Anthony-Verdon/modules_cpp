/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:54 by averdon           #+#    #+#             */
/*   Updated: 2023/03/01 14:28:02 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
#include <ostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &instance);
		Fixed& 	operator = (const Fixed &instance);
		bool	operator > (const Fixed &instance);
		bool	operator < (const Fixed &instance);
		bool	operator >= (const Fixed &instance);
		bool	operator <= (const Fixed &instance);
		bool	operator == (const Fixed &instance);
		bool	operator != (const Fixed &instance);
		Fixed operator + (const Fixed &instance);
		Fixed operator - (const Fixed &instance);
		Fixed operator * (const Fixed &instance);
		Fixed operator / (const Fixed &instance);
		Fixed& operator ++ (void);
		Fixed operator ++ (int);
		Fixed& operator -- (void);
		Fixed operator -- (int);
		~Fixed(void);

		int 	getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		void	setRawBits(const int raw);
		
		static const Fixed&	min(const Fixed& nb1, const Fixed& nb2);
		static Fixed&		min(Fixed& nb1, Fixed& nb2);
		static const Fixed&	max(const Fixed& nb1, const Fixed& nb2);
		static Fixed&		max(Fixed& nb1, Fixed& nb2);
	
	private:
		int 				_rawBits;
		static const int	_nb_bits_fract_part = 8;
};

std::ostream& operator << (std::ostream& os, const Fixed& instance);

#endif

