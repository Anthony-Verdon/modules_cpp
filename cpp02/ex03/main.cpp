/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:40:09 by averdon           #+#    #+#             */
/*   Updated: 2023/03/01 14:21:47 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point a(0, 20);
	Point b(-20, -20);
	Point c(20, -20);

	Point d(-40, 10);
	Point e(-10, -10);
	Point f(10, -10);
	Point g(0, 10);

	std::cout << bsp(a, b, c, d) << "\n";
	std::cout << bsp(a, b, c, e) << "\n";
	std::cout << bsp(a, b, c, f) << "\n";
	std::cout << bsp(a, b, c, g) << "\n";
	return (0);
}
