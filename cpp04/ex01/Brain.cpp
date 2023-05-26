/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:41:52 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:44:58 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain initialized\n";
}

Brain::~Brain(void)
{
	std::cout << "Brain stopped\n";
}

Brain::Brain(const Brain &copy){
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain & Brain::operator=(const Brain &copy){
	if (&copy != this)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > 99)
		return ;
	this->_ideas[index] = idea;
}

std::string	Brain::getIdea(int index)
{
	if (index < 0 || index > 99)
		return ("No idea");
	return (this->_ideas[index]);
}
