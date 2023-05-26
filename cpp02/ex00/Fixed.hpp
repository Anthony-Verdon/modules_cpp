/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:54 by averdon           #+#    #+#             */
/*   Updated: 2023/02/27 13:59:14 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed &instance);
		Fixed& operator=(const Fixed &instance);
		~Fixed(void);

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int 				_rawBits;
		static const int	_nb_bits_fract_part = 8;
};

#endif

