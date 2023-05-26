#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
 {
 	 public:
		static bool			is_digit(std::string string);
		static bool			is_digit_float(std::string string);
		static bool 		is_valid_date(int i_day, int i_month, int i_year);
		static bool			check_date(std::string line);
		static bool			check_database(std::map<std::string, double> & database);
		static bool			check_line_input(std::string line, int nb_line);
		static std::string	find_nearest_date(std::map<std::string, double> database,
								std::string date);
		static void			use_input(char *input, std::map<std::string, double> database);
 	 private:
 		BitcoinExchange();
 		~BitcoinExchange();
 		BitcoinExchange (const BitcoinExchange &copy);
 		BitcoinExchange &operator=(const BitcoinExchange&);
 		
 };

#endif
