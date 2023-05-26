/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:34:21 by averdon           #+#    #+#             */
/*   Updated: 2023/03/05 12:20:01 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	 public:
		Cure(void);
		~Cure(void);
		Cure (const Cure &copy);
		Cure &operator=(const Cure&);
		
		Cure*	clone(void) const;
		void	use(ICharacter& target);

	 private:
		
};

#endif
