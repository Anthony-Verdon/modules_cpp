/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:42:31 by averdon           #+#    #+#             */
/*   Updated: 2023/03/05 14:58:54 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	 public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource (const MateriaSource &copy);
		MateriaSource &operator=(const MateriaSource&);

		void		learnMateria(AMateria *Materia);
		AMateria	*createMateria(std::string const & type);
		AMateria	**getMateria(void);
	 private:
		AMateria	*_source[4];
		
};

#endif
