/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:43:48 by averdon           #+#    #+#             */
/*   Updated: 2023/05/19 11:28:39 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
#include <cstdlib>

#define MAX_VAL 750

int main(void)
{
	{
		std::cout << "[TEST MAIN GIVEN]\n";
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		Array<int> je = numbers;
		je = numbers;
		je = numbers;
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cout << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	{
		std::cout << "[MY MAIN]\n";
		try
		{
			Array<int> array1;
			std::cout << array1[0] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		try
		{
			Array<int> array2(-5);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		try
		{
			Array<int> array3(0);
			std::cout << array3[0] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		try
		{
			Array<int> array4(5);
			int * test = new int[5];
			for (int i = 0; i < 5; i++)
				std::cout << array4[i]  << "\n";
			Array<int> array5(array4);
			for (int i = 0; i < 5; i++)
				array4[i] = 1;
			for (int i = 0; i < 5; i++)
				std::cout << array4[i] << " " << array5[i]<< "\n";
			array5 = array4;
			for (int i = 0; i < 5; i++)
				array4[i] = 2;
			for (int i = 0; i < 5; i++)
				std::cout << array4[i] << " " << array5[i]<< "\n";
			delete [] test;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	return (0);
}
