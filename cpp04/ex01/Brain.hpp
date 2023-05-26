/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:41:57 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:43:31 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	 public:
		Brain(void);
		~Brain(void);
		Brain (const Brain &copy);
		Brain &operator=(const Brain&);

		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index);
	 private:
		std::string _ideas[100];
		
};

#endif
