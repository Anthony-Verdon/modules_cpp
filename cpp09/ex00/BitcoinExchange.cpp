#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>

const int INPUT = 0;
const int DATA = 1;
std::map<std::string, double> BitcoinExchange::database;

bool BitcoinExchange::isLeap(const int & year) {
	if (year % 4 == 0 && year % 100 != 0)
		return (true);
	return (false);
}

bool BitcoinExchange::dateValid(const std::string & date) {
	int year;
	int month;
	int day;
	size_t rod1Pos;
	size_t rod2Pos;
	char *endPos;
	
	if (date.length() == 0)
		return (false);
	rod1Pos = date.find("-");
	if (rod1Pos == std::string::npos)
		return (false);
	rod2Pos = date.find("-", rod1Pos + 1);
	if (rod2Pos == std::string::npos)
		return (false);
	
	year = strtol(date.substr(0, rod1Pos).c_str(), &endPos, 10);
	if (*endPos != '\0' || errno == ERANGE
		|| date.substr(0, rod1Pos).find_first_not_of("0123456789") != std::string::npos)
		return (false);
	month = strtol(date.substr(rod1Pos + 1, rod2Pos - rod1Pos - 1).c_str(), &endPos, 10);
	if (*endPos != '\0' || errno == ERANGE
		|| date.substr(rod1Pos + 1, rod2Pos - rod1Pos - 1).find_first_not_of("0123456789") != std::string::npos)
		return (false);
	day = strtol(date.substr(rod2Pos + 1, date.length() - rod2Pos - 1).c_str(), &endPos, 10);
	if (*endPos != '\0' || errno == ERANGE
		|| date.substr(rod2Pos + 1, date.length() - rod2Pos - 1).find_first_not_of("0123456789") != std::string::npos)
		return (false);

	if (year < 2009)
		return (false);
	if (month < 0 || month > 12)
		return (false);
	if ((month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12) && (day < 1 || day > 31))
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
		return (false);
	if (month == 2 &&
		((isLeap(year) && (day < 1 || day > 29))
		 || (!isLeap(year) && (day < 1 || day > 28))))
		return (false);
	return (true);
}

bool BitcoinExchange::valueValid(const std::string & value, const int & file) {
	char *endPos;
	double rv;
	if (value.length() == 0)
		return (false);
	if (value.find_first_not_of("0123456789.") != std::string::npos)
		return (false);
	rv = std::strtof(value.c_str(), &endPos);
	if (*endPos != '\0' || errno == ERANGE)
		return (false);
	if (file == INPUT && (rv < 0 || rv > 1000))
		return (false);
	return (true);
}

void BitcoinExchange::readDatabase(std::ifstream & infile){
	std::string line;
	std::string date;
	std::string value;
	size_t quotePosition;

	std::getline(infile, line);
	if (line.length() == 0)
		throw ("data.csv empty.\n");
	else if (line != "date,exchange_rate")
		throw ("first line of data.csv should be \"date,exchange_rate\".\n");
	while (std::getline(infile, line))
	{
		quotePosition = line.find(",");
		if (quotePosition == std::string::npos)
			throw ("line invalid in data.csv.\n");
		date = line.substr(0, quotePosition);
		value = line.substr(quotePosition + 1, line.length());
		if (dateValid(date) && valueValid(value, DATA))
			database[date] = std::strtod(value.c_str(), NULL);
		else
			throw ("line invalid in data.csv.\n");
	}
	if (database.empty())
		throw ("data.csv empty.\n");
}

void BitcoinExchange::parseDatabase() {
	std::ifstream infile("data.csv");
	if (infile.is_open())
			readDatabase(infile);
	else
		throw ("can't open data.csv.\n");
}

void BitcoinExchange::readInput(std::ifstream & infile) {
	std::string line;
	std::string date;
	std::string value;
	size_t pipePosition;
	std::map<std::string, double>::iterator it;

	std::getline(infile, line);
	if (line.length() == 0)
		throw ("input file empty.\n");
	else if (line != "date | value")
		throw ("first line of input file should be \"date | value\".\n");
	while (std::getline(infile, line))
	{
		pipePosition = line.find("|");
		if (pipePosition == std::string::npos || line[pipePosition - 1] != ' ' || line[pipePosition + 1] != ' ')
		{
			std::cerr << ("line invalid in input file.\n");
			continue ;
		}
		date = line.substr(0, pipePosition - 1);
		value = line.substr(pipePosition + 2, line.length());
		if (dateValid(date) && valueValid(value, INPUT))
		{
			it = database.upper_bound(date);
			if (it != database.begin())
			{
				--it;
				std::cout << date << " => " << std::strtof(value.c_str(), NULL) * it->second << "\n";
			}
			else
				std::cerr << "line invalid in input file.\n";
		}
		else
			std::cerr << "line invalid in input file.\n";
	}
	if (database.empty())
		std::cerr << ("input file empty.\n");
}

void BitcoinExchange::parseInput(const char * inputFile) {
	std::ifstream infile(inputFile);
	if (infile.is_open())
			readInput(infile);
	else
		throw ("can't open input file.\n");
}

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
	*this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &copy){
	if (&copy != this)
	{
		this->database = copy.database;
	}
	return (*this);
}
