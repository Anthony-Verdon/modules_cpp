#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::map<std::string, double>	database;
	if (argc != 2)
	{
		std::cerr << "Program only take one argument, on the format <name>\n";
		return (1);
	}
	else if (BitcoinExchange::check_database(database) == false)
		return (2);
	BitcoinExchange::use_input(argv[1], database);
	return (0);
}
