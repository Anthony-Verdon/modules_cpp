/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:26:02 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 11:21:29 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	 public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap (const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap&);
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	 protected:
		std::string _name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;
		
};
#endif
