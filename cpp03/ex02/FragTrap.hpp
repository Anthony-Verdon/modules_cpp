/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:57:04 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 11:19:10 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	 public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap (const FragTrap &copy);
		FragTrap &operator=(const FragTrap&);

		void	highFivesGuys(void);
};

#endif
