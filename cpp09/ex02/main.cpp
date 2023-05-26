#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>

bool is_digit(std::string string)
{
	for (int i = 0; string[i]; i++)
	{
		if (string[i] < '0' || string[i] > '9')
			return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "no arguments.\n";
		return (1);
	}

	int nb_tmp;

	for (int i = 1; i < argc; i++)
	{
		nb_tmp = strtol(argv[i], NULL, 10);
		if (errno != 0 || !is_digit(argv[i]) || nb_tmp < 0)
		{
			std::cerr << "invalid argument.\n" << argv[i];
			if (errno != 0)
				std::cerr << " create an overflow.\n";
			else if (!is_digit(argv[i]))
				std::cerr << " isn't a valid number.\n";
			else
				std::cerr << " is a negative number.\n";
			return (1);
		}
	}

	PmergeMe::start_algorithm(argc, argv);
	return (0);
}
