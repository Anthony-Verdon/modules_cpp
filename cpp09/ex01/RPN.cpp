#include "RPN.hpp"
#include <iostream>

bool	RPN::is_digit(const char arg)
{
	if (arg < '0' || arg > '9')
		return (false);
	return (true);
}

bool	RPN::is_operator(const char arg)
{
	if (arg != '+' && arg != '-' && arg != '*' && arg != '/')
		return (false);
	return (true);
}

void 	RPN::calculate(std::stack<int> & numbers, char calculus_operator)
{
	if (numbers.empty())	
		throw ("calcul impossible.\n");
	int nb_2 = numbers.top();
	numbers.pop();
	if (numbers.empty())	
		throw ("calcul impossible.\n");
	int nb_1 = numbers.top();
	numbers.pop();
	int result;
	switch (calculus_operator)
	{
		case '+':
			result = nb_1 + nb_2;
			numbers.push(result);
			break;
		case '-':
			result = nb_1 - nb_2;
			numbers.push(result);
			break;
		case '*':
			result = nb_1 * nb_2;
			numbers.push(result);
			break;
		case '/':
			if (nb_2 == 0)
				throw ("division by 0 is forbidden.\n");
			result = nb_1 / nb_2;
			numbers.push(result);
			break;
	}
}

void	RPN::interpret(char *arg)
{
	std::stack<int> numbers;
	for (size_t i = 0; arg[i]; i++)
	{
		if (is_operator(arg[i]) && (arg[i + 1] == ' ' || arg[i + 1] == '\0'))
			calculate(numbers, arg[i]);
		else if (is_digit(arg[i]) && (arg[i + 1] == ' ' || arg[i + 1] == '\0'))
			numbers.push(arg[i] - '0');
		else if (arg[i] == ' ')
			continue;
		else
			throw ("invalid argument.\n");
	}
	if (numbers.size() != 1)
		throw ("calcul impossible.\n");
	std::cout << "result: " << numbers.top() << ".\n";
}
