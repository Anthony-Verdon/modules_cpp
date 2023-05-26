/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:47:35 by averdon           #+#    #+#             */
/*   Updated: 2023/03/14 19:03:13 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base	*generate(void)
{
	srand(time(NULL));
	int	random = rand() % 3;
	switch (random)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p is originally a class A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "p is originally a class B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "p is originally a class C\n";
}

void	identify(Base &p)
{
	try
	{
		A object = dynamic_cast<A&>(p);
		std::cout << "p is originally a class A\n";
	}
	catch(std::exception & e)
	{
		std::cout << "dynamic_cast throw a " << e.what() << "\n";
	}
	try
	{
		B object = dynamic_cast<B&>(p);
		std::cout << "p is originally a class B\n";
	}
	catch(std::exception & e)
	{
		std::cout << "dynamic_cast throw a " << e.what() << "\n";
	}
	try
	{
		C object = dynamic_cast<C&>(p);
		std::cout << "p is originally a class C\n";
	}
	catch(std::exception & e)
	{
		std::cout << "dynamic_cast throw a " << e.what() << "\n";
	}
}

int	main(void)
{
	Base *object = generate();
	identify(*object);
	identify(NULL);
	delete object;
	return (0);
}
