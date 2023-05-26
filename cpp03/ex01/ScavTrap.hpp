/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:57:04 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 11:15:22 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	 public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap (const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap&);

		void	attack(const std::string& target);
		void	guardGate(void);
	private:
		bool 	_inGuardGate;
};

#endif
