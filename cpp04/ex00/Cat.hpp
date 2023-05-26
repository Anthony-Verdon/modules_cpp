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

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	 public:
		Cat(void);
		~Cat(void);
		Cat (const Cat &copy);
		Cat &operator=(const Cat&);
		
		void	makeSound(void) const;
	 private:
		
};

#endif
