/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:47:01 by averdon           #+#    #+#             */
/*   Updated: 2023/03/04 17:35:28 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AbstractAnimal.hpp"
# include "Brain.hpp"

class Dog : public AbstractAnimal
{
	 public:
		Dog(void);
		virtual ~Dog(void);
		Dog (const Dog &copy);
		Dog &operator=(const Dog&);
		
		virtual void	makeSound(void) const;
	 private:
		Brain *_brain;
		
};

#endif
