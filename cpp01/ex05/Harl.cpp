/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:26:31 by averdon           #+#    #+#             */
/*   Updated: 2023/03/15 15:11:20 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl constructed\n";
}

Harl::~Harl(void)
{
	std::cout << "Harl destructed\n";
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now.\n";
}

void Harl::basic(void)
{
	std::cout << "I don't care !\n";
}

void Harl::complain(std::string level)
{
	std::string levels_name[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::* levels_functions[5])(void) = {&Harl::debug, &Harl::info,
						&Harl::warning, &Harl::error, &Harl::basic};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(levels_name[i]) == 0)
		{
			(this->*levels_functions[i])();
			return ; 
		}
	}
	(this->*levels_functions[4])();
}
