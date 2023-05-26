#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
	 public:
		Span();
		Span(int N);
		~Span();
		Span (const Span &copy);
		Span &operator=(const Span&);

		void	addNumber(int number);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
	 private:
		std::vector<int> vector;
		int	_nb_elements;
		int	_length_array;
		
};

#endif
