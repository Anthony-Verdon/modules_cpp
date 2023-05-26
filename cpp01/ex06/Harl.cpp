/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:26:31 by averdon           #+#    #+#             */
/*   Updated: 2023/03/16 18:54:20 by averdon          ###   ########.fr       */
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
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}

void Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable ! I want to speak to the manager now.\n";
}

void Harl::basic(void)
{
	std::cout << "I don't care !\n";
}

void Harl::complain(std::string level)
{
	std::string levels_name[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int 		i;

	i = 0;
	while (i < 4)
	{
		if (level.compare(levels_name[i]) == 0)
		{
			switch (i)
			{
				case 0:
					this->debug();
					__attribute__((fallthrough));
				case 1:
					this->info();
					__attribute__((fallthrough));
				case 2:
					this->warning();
					__attribute__((fallthrough));
				case 3:
					this->error();
					__attribute__((fallthrough));
				case 4:
					return ;
			}
		}
		i++;
	}
	this->basic();
}
