#include "RPN.hpp"

//gérer division par 0
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments. Example of use : \"./RPN \"8 9 *\" \"\n";
		return (1);
	}
	std::stack<std::string> stack;
	if (RPN::create_stack(stack, argv[1]) == true)
		RPN::calculate(stack);
	else
		std::cerr << "Invalid line.\n";
	return (0);
}
