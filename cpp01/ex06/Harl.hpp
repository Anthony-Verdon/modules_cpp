/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:26:43 by averdon           #+#    #+#             */
/*   Updated: 2023/02/27 10:33:41 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void basic(void);
};

#endif


