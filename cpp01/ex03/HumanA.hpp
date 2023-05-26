/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:23 by averdon           #+#    #+#             */
/*   Updated: 2023/02/23 13:59:36 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP

# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA
{
	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void attack(void);

	private:
		std::string _name;
		Weapon 		&_weapon;
};

#endif
