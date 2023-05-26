#include "BitcoinExchange.hpp"

bool	BitcoinExchange::is_digit(std::string string)
{
	for (int i = 0; string[i]; i++)
	{
		if (i == 0 && (string[i] == '+' || string[i] == '-'))
			i++;
		if (string[i] < '0' || string[i] > '9')
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::is_digit_float(std::string string)
{
	bool	dot = false;

	for (int i = 0; string[i]; i++)
	{
		if (i == 0 && (string[i] == '+' || string[i] == '-'))
			i++;
		if (string[i] == '.' && dot == false)
			dot = true;
		else if (string[i] == '.' && dot == true)
			return (false);
		else if (string[i] < '0' || string[i] > '9')
			return (false);
	}
	return (true);
}

bool BitcoinExchange::is_valid_date(int i_day, int i_month, int i_year)
{
	if (i_month < 1 || i_month > 12)
		return (false);
	else if (i_month <= 7
			&& ((i_month % 2 == 0 && i_month != 2 && (i_day < 1 || i_day > 30))
			|| (i_month % 2 == 1 && (i_day < 1 || i_day > 31))))
		return (false);
	else if (i_month > 7
			&& ((i_month % 2 == 1 && i_month != 2 && (i_day < 1 || i_day > 30))
			|| (i_month % 2 == 0 && (i_day < 1 || i_day > 31))))
		return (false);
	else if (i_year % 4 == 0 && i_month == 2)
	{
		if (i_year % 100 == 0 && i_year % 400 != 0 && (i_day < 1 || i_day > 28))
				return (false);
		else if (i_day < 1 || i_day > 29)
				return (false);
	}
	else if (i_month == 2 && (i_day < 1 || i_day > 28))
		return (false);
	return (true);
}
