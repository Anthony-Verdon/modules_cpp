#include "Span.hpp"
#include <cstdlib>
#include <climits>
#include <cmath>
#include <exception>
#include <stdexcept>

Span::Span(void){
	this->_nb_elements = 0;
	this->_length_array = 0;
}

Span::Span(int N){
	if (N >= 0)
	{
		this->_nb_elements = 0;
		this->_length_array = N;
	}
	else
		throw(std::logic_error("InvalidArgumentException"));
}

Span::~Span(){
}

Span::Span(const Span &copy){
	*this = copy;
}

Span & Span::operator=(const Span &copy){
	if (&copy != this)
	{
		this->vector = copy.vector;
		this->_nb_elements = copy._nb_elements;
		this->_length_array = copy._length_array;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->_nb_elements < this->_length_array)
	{
		vector.push_back(number);
		this->_nb_elements += 1;
	}
	else
		throw(std::logic_error("Span full"));
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	int nb_elements_range = 0;
	for (std::vector<int>::iterator it = begin; it != end; it++)
		nb_elements_range++;
	if (this->_nb_elements + nb_elements_range < this->_length_array)
	{
		for (std::vector<int>::iterator it = begin; it != end; it++)
		{
			vector.push_back(*it);
			this->_nb_elements += 1;
		}
	}
	else
		throw(std::logic_error("Span full"));
}

unsigned int	Span::shortestSpan(void)
{
	if (this->_nb_elements < 2)
		throw(std::logic_error("Span has less than 2 members"));

	unsigned int	shortestSpan;

	shortestSpan = UINT_MAX;
	for (int i = 0; i < this->_nb_elements; i++)
	{
		for (int j = i + 1; j < this->_nb_elements; j++)
		{
			if (std::abs(static_cast<long>(vector[i]) - static_cast<long>(vector[j])) < shortestSpan)
				shortestSpan = std::abs(static_cast<long>(vector[i]) - static_cast<long>(vector[j]));
		}
	}
	return (shortestSpan);
}

unsigned int	Span::longestSpan(void)
{
	if (this->_nb_elements < 2)
		throw(std::logic_error("Span has less than 2 members"));

	unsigned int	longestSpan;

	longestSpan = 0;
	for (int i = 0; i < this->_nb_elements; i++)
	{
		for (int j = i + 1; j < this->_nb_elements; j++)
		{
			if (std::abs(static_cast<long>(vector[i]) - static_cast<long>(vector[j])) > longestSpan)
				longestSpan = std::abs(static_cast<long>(vector[i]) - static_cast<long>(vector[j]));
		}
	}
	return (longestSpan);
}
