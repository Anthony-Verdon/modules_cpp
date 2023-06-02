#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw ("Program take one argument.\n");
		BitcoinExchange::parseDatabase();
		BitcoinExchange::parseInput(argv[1]);
		return (0);
	}
	catch (const char * error)
	{
		std::cerr << error;
		return (1);
	}
}
