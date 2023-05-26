/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:54 by averdon           #+#    #+#             */
/*   Updated: 2023/02/28 13:54:12 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &instance);
		Fixed& operator = (const Fixed &instance);
		~Fixed(void);

		int 	getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		void	setRawBits(const int raw);
	
	private:
		int 				_rawBits;
		static const int	_nb_bits_fract_part = 8;
};

std::ostream& operator << (std::ostream& os, const Fixed& instance);

#endif

