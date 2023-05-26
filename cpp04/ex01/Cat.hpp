/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:48:38 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:17:05 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	 public:
		Cat(void);
		virtual ~Cat(void);
		Cat (const Cat &copy);
		Cat &operator=(const Cat&);
		
		virtual void	makeSound(void) const;
		Brain *getBrain(void);
	 private:
		Brain *_brain;
		
};

#endif
