#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

class RPN
{
	 public:
		static bool	is_digit(const char arg);
		static bool	is_operator(const char arg);
		static bool	create_stack(std::stack <std::string> & stack, std::string arg);
		static void	calculate(std::stack<std::string> stack);
	 private:
		RPN();
		~RPN();
		RPN (const RPN &copy);
		RPN &operator=(const RPN&);
		
};

#endif
