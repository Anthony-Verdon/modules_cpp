#include "BitcoinExchange.hpp"

bool	BitcoinExchange::check_date(std::string line)
{
	std::string s_year = line.substr(0, 4);
	std::string s_month = line.substr(5, 2);
	std::string s_day = line.substr(8, 2);
	
	int	i_year = std::strtol(s_year.c_str(), NULL, 10);
	int	i_month = std::strtol(s_month.c_str(), NULL, 10);
	int	i_day = std::strtol(s_day.c_str(), NULL, 10);

	if (!is_digit(s_year) || !is_digit(s_month) || !is_digit(s_day)
		|| i_year < 2009 || i_year > 9999
		|| !is_valid_date(i_day, i_month, i_year))
		return (false);
	return (true);
}

bool	BitcoinExchange::check_database(std::map<std::string, double> & database)
{
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
	{
		std::cerr << "can't open data file. Format : data.csv\n";
		return (false);
	}
	std::string line;
	std::string date;
	std::getline(dataFile, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "line invalid in data.csv\nLine :" << line << "\n";
		dataFile.close();
		return (false);
	}
	while (std::getline(dataFile, line))
	{
		if (line[4] != '-' || line[7] != '-' || line[10] != ','
				|| !is_digit_float(&line[11]))
		{
			std::cerr << "syntax invalid in data.csv\nLine : " << line << "\n";
			dataFile.close();
			return (false);
		}
		else if (!check_date(line))
		{
			std::cerr << "date invalid in data.csv\nLine : " << line << "\n";
			dataFile.close();
			return (false);
		}
		date = line;
		date[4] = date[5];
		date[5] = date[6];
		date[6] = date[8];
		date[7] = date[9];
		for (size_t i = 8; i < line.length(); i++)
			date[i] = '\0';
		database[date] = strtof(&line[11], NULL);
		if (errno != 0)
		{
			std::cerr << "value invalid in data.csv\nLine : " << line << "\n";
			dataFile.close();
			return (false);
		}

	}
	dataFile.close();
	if (database.empty())
	{	
		std::cerr << "data.csv is empty\n";
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::check_line_input(std::string line, int nb_line)
{
	if (line.length() < 13 || line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' '
			|| !check_date(line)
			|| !is_digit_float(static_cast<char *>(&line[13]))
			|| strtof(static_cast<char *>(&line[13]), NULL) < 0
			|| strtof(static_cast<char *>(&line[13]), NULL) > 1000
			|| errno != 0)
	{
		std::cerr << "\033[1;31mline invalid in input file\nLine " << nb_line << " : " << line << "\n\033[0m";
		return (false);
	}
	return (true);
}
