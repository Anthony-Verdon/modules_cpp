#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN
{
	 public:
		static bool	is_digit(const char arg);
		static bool	is_operator(const char arg);
		static void	interpret(char *arg);
		static void calculate(std::stack<int> & numbers, char calculus_operator);
	 private:
		RPN();
		~RPN();
		RPN (const RPN &copy);
		RPN &operator=(const RPN&);
		
};

#endif
