/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:26:15 by averdon           #+#    #+#             */
/*   Updated: 2023/02/27 10:40:43 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl instance;

	instance.complain("DEBUG");
	instance.complain("INFO");
	instance.complain("WARNING");
	instance.complain("ERROR");
	instance.complain("errrorr");
	return (0);
}
