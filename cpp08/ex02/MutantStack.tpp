#include "MutantStack.hpp"

template<typename T, typename U>

MutantStack<T, U>::MutantStack() : std::stack<T, U>(){
}

template<typename T, typename U>

MutantStack<T, U>::~MutantStack(){
}

template<typename T, typename U>

MutantStack<T, U>::MutantStack(const MutantStack &copy) : std::stack<T, U>(){
	*this = copy;
}

template<typename T, typename U>

MutantStack<T, U> & MutantStack<T, U>::operator=(const MutantStack &copy){
	if (&copy != this)
	{

	}
	return (*this);
}
