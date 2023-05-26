/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:28:45 by averdon           #+#    #+#             */
/*   Updated: 2023/05/16 11:28:10 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>

class ICharacter;

class AMateria
{
	 public:
		AMateria(void);
		AMateria(std::string const & type);
		virtual ~AMateria(void);
		AMateria (const AMateria &copy);
		AMateria &operator=(const AMateria&);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
		
	protected:
		const  std::string _type;

};

#endif
