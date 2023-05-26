/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:44:21 by averdon           #+#    #+#             */
/*   Updated: 2023/03/04 17:37:21 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const AbstractAnimal* animals[100];
	for (int i = 0; i < 50; i++)
		animals[i] = new Dog();
	for (int i = 50; i < 100; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 100; i++)
		delete animals[i];
	
	//const AbstractAnimal *AbstractAnimal = new AbstractAnimal();
	return (0);
}
