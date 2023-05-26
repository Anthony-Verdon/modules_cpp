/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:19:15 by averdon           #+#    #+#             */
/*   Updated: 2023/03/14 18:36:52 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		*data;
	uintptr_t	value;

	data = new Data;
	data->informations = "blablabla";
	data->nb_person = 10;
	value = Serializer::serialize(data);
	std::cout << value << "\n";
	data = Serializer::deserialize(value);
	std::cout << data << "\n";
	value = Serializer::serialize(data);
	std::cout << value << "\n";
	data = Serializer::deserialize(value);
	std::cout << data << "\n";
	delete (data);
	return (0);
}
