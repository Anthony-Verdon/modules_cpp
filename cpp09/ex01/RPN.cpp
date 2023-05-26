#include "RPN.hpp"

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

void	RPN::calculate(std::stack<std::string> stack)
{
	std::stack<std::string> result_stack;
	float				result;
	std::string			first_number;
	std::string			second_number;
	std::string			calcul_operator;
	std::ostringstream	oss;

	if (stack.size() == 1)
	{
		result_stack.push(stack.top());
		stack.pop();
	}
	while (stack.size() >= 1)
	{
		calcul_operator = stack.top();
		while (!is_operator(calcul_operator[0]))
		{
			result_stack.push(stack.top());
			stack.pop();
			calcul_operator = stack.top();
		}
		stack.pop();
		second_number = result_stack.top();
		result_stack.pop();
		first_number = result_stack.top();
		result_stack.pop();
		result = atoi(first_number.c_str());
		if (calcul_operator == "+")
			result += atoi(second_number.c_str());
		else if (calcul_operator == "-")
			result -= atoi(second_number.c_str());
		else if (calcul_operator == "*")
			result *= atoi(second_number.c_str());
		else if (calcul_operator == "/")
		{
			if (atoi(second_number.c_str()) != 0)
				result /= atoi(second_number.c_str());
			else
			{
				std::cerr << "division by 0 is forbidden\n";
				return ;
			}
		}
		oss << result;
		result_stack.push(oss.str());
		oss.str("");
		oss.clear();

	}
	std::cout << "result : " << result_stack.top() << "\n";
}

bool	RPN::create_stack(std::stack <std::string> & stack, std::string arg)
{
	std::string tmp;
	bool onSpace = false;
	int nb_number = 0;
	int nb_operator = 0;

	for (int i = arg.length() - 1; i >= 0; i--)
	{
		if ((is_operator(arg[i]) || is_digit(arg[i])) && onSpace == false)
		{
			tmp = arg[i];
			stack.push(tmp);
			onSpace = true;
			if (is_operator(arg[i]))
				nb_operator++;
			else
				nb_number++;
		}
		else if (arg[i] == ' ' && onSpace == true)
			onSpace = false;
		else
			return (false);
	}
	if (nb_number - 1 != nb_operator)
		return (false);
	return (true);
}
