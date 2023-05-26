/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:36:57 by averdon           #+#    #+#             */
/*   Updated: 2023/02/23 14:16:21 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP

# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB
{
	public:

		HumanB(std::string name);
		~HumanB(void);
		void attack(void);
		void setWeapon(Weapon &weapon);

	private:
		std::string _name;
		Weapon 		*_weapon;
};

#endif


