/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:21:49 by averdon           #+#    #+#             */
/*   Updated: 2023/02/23 11:21:42 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string&	getType(void);
		void				setType(std::string type);

	private:
		std::string	_type;
};

#endif
