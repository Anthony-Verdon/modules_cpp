#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <string>

std::string BitcoinExchange::find_nearest_date(std::map<std::string, double> database, std::string date)
{
	std::string nearest_date;

	nearest_date = "-1";
	for (std::map<std::string, double>::iterator it = database.begin(); it != database.end(); it++)
	{
		if (std::strtol(it->first.c_str(), NULL, 10) > std::strtol(nearest_date.c_str(), NULL, 10)
			&& std::strtol(it->first.c_str(), NULL, 10) < std::strtol(date.c_str(), NULL, 10))
			nearest_date = it->first;
	}
	return (nearest_date);
}

void	BitcoinExchange::use_input(char *input, std::map<std::string, double> database)
{
	std::ifstream inputFile(input);
	if (!inputFile.is_open())
	{
		std::cerr << "can't open input file.\n";
		return ;
	}
	std::string line;
	std::string date;
	std::string date_clean;
	std::string nearest_date;
	std::getline(inputFile, line);
	if (line != "date | value")
	{
		std::cerr << "line invalid in input file\nLine :" << line << "\n";
		inputFile.close();
		return ;
	}
	int	nb_line = 1;
	while (std::getline(inputFile, line))
	{
		if (check_line_input(line, nb_line) == true)
		{
			date = line;
			date[4] = date[5];
			date[5] = date[6];
			date[6] = date[8];
			date[7] = date[9];
			for (size_t i = 8; i < line.length(); i++)
				date[i] = '\0';
			date_clean = line;
			for (size_t i = 10; i < line.length(); i++)
				date_clean[i] = '\0';
			if (database.find(date) == database.end())
				nearest_date = find_nearest_date(database, date);
			else
				nearest_date = date;
			if (nearest_date == "-1")
				std::cout << "no value found for " << date_clean << "or before\n";	
			else
				std::cout << date_clean << " => " << database[nearest_date] * strtof(&line[13], NULL) << "\n";
		}
		nb_line++;
	}
	inputFile.close();
}
