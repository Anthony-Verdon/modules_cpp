/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:44:21 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:42:28 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* animals[100];
	
	for (int i = 0; i < 50; i++)
	{
		animals[i] = new Dog();
		for (int j = 0; j < 100; j++)
			((Dog *)(animals[i]))->getBrain()->setIdea(j, "wouf\n");
	}
	for (int i = 50; i < 100; i++)
	{
		animals[i] = new Cat();
		for (int j = 0; j < 100; j++)
			((Cat *)(animals[i]))->getBrain()->setIdea(j, "miaou\n");
	}
	
	Dog new_dog = (*((Dog *)(animals[25])));
	Dog new_dog_2 = (*((Dog *)(animals[25])));
	Cat new_cat(*((Cat *)(animals[75])));
	Cat new_cat_2(*((Cat *)(animals[75])));
	std::cout << new_cat.getBrain()->getIdea(2);
	std::cout << new_dog.getBrain()->getIdea(2);
	std::cout << new_cat_2.getBrain()->getIdea(2);
	std::cout << new_dog_2.getBrain()->getIdea(2);
	new_cat.getBrain()->setIdea(2, "miaou miaou\n");
	new_dog.getBrain()->setIdea(2, "wouf wouf\n");
	std::cout << new_cat.getBrain()->getIdea(2);
	std::cout << new_dog.getBrain()->getIdea(2);
	std::cout << new_cat_2.getBrain()->getIdea(2);
	std::cout << new_dog_2.getBrain()->getIdea(2);
	new_dog = new_dog_2;
	new_dog_2 = new_dog;
	for (int i = 0; i < 100; i++)
		delete animals[i];
	return (0);
}
