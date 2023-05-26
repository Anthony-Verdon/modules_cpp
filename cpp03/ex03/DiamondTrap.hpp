/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:48:04 by averdon           #+#    #+#             */
/*   Updated: 2023/03/03 14:28:55 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
	 public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		DiamondTrap (const DiamondTrap &copy);
		DiamondTrap &operator=(const DiamondTrap&);

		void	whoAmI(void);
		using	ScavTrap::attack;
	 private:
		std::string	_name;
};
#endif
