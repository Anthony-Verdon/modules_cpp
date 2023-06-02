#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw ("only one argument accepted.\n");
		RPN::interpret(argv[1]);
		return (0);
	}
	catch (const char *error)
	{
		std::cerr << error;
		return (1);
	}
}
