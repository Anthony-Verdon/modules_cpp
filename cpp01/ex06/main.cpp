/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:26:15 by averdon           #+#    #+#             */
/*   Updated: 2023/03/16 18:54:48 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{

	if (argc != 2)
		return (1);
	Harl instance;
	instance.complain(argv[1]);
	return (0);
}
