/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:43:59 by averdon           #+#    #+#             */
/*   Updated: 2023/03/05 15:43:58 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	 public:
		Character(void);
		Character(std::string name);
		~Character(void);
		Character (const Character &copy);
		Character &operator=(const Character&);

		std::string const & getName(void) const;
		void 				equip(AMateria *Materia);
		void				unequip(int index);
		void				use(int index, ICharacter & target);
		AMateria			**getInventory(void);
	 private:
		AMateria	*_inventory[4];
		std::string	_name;
		
};

#endif
