/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:48:38 by averdon           #+#    #+#             */
/*   Updated: 2023/03/04 17:35:14 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AbstractAnimal.hpp"
# include "Brain.hpp"

class Cat : public AbstractAnimal
{
	 public:
		Cat(void);
		virtual ~Cat(void);
		Cat (const Cat &copy);
		Cat &operator=(const Cat&);
		
		virtual void	makeSound(void) const;
	 private:
		Brain *_brain;
		
};

#endif
