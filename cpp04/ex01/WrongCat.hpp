/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:48:38 by averdon           #+#    #+#             */
/*   Updated: 2023/03/03 19:36:44 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	 public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat (const WrongCat &copy);
		WrongCat &operator=(const WrongCat&);
		
		void	makeSound(void) const;
	 private:
		
};

#endif
