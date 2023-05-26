/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:47:01 by averdon           #+#    #+#             */
/*   Updated: 2023/03/03 19:36:50 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	 public:
		Dog(void);
		~Dog(void);
		Dog (const Dog &copy);
		Dog &operator=(const Dog&);
		
		void	makeSound(void) const;
	 private:
		
};

#endif
