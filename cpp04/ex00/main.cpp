/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:44:21 by averdon           #+#    #+#             */
/*   Updated: 2023/03/03 19:38:07 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* animal = new Animal();
		std::cout << animal->getType() << " " << std::endl;
		animal->makeSound();
		delete animal;
		std::cout << std::endl;
	}
	{
		const Animal* dog = new Dog();
		std::cout << dog->getType() << " " << std::endl;
		dog->makeSound();
		delete dog;
		std::cout << std::endl;
	}
	{
		const Animal* cat = new Cat();
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
	}
	{
		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound();
		delete wrongCat;
	}
	return (0);
}
