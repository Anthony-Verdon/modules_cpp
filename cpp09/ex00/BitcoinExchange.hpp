#pragma once

#include <map>
#include <string>
#include <fstream>

class BitcoinExchange
{
	 public:
		static void parseDatabase();
		static void parseInput( const char *inputFile);
	 private:
	 	static std::map<std::string, double> database;
	 
	 private:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange (const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		static void readInput(std::ifstream & infile) ;
		static void readDatabase(std::ifstream & infile);
		static bool valueValid(const std::string & value,const int & file);
		static bool dateValid(const std::string & date);
		static bool isLeap(const int & year);
		
};
