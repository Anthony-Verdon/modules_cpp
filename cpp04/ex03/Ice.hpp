/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:33:15 by averdon           #+#    #+#             */
/*   Updated: 2023/03/05 12:05:50 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	 public:
		Ice(void);
		~Ice(void);
		Ice (const Ice &copy);
		Ice &operator=(const Ice&);

		Ice*	clone(void) const;
		void	use(ICharacter& target);

	 private:
		
};

#endif
