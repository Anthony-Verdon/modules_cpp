#ifndef ARRAY_TPP
# define ARRAY_TPP
 
#include "Array.hpp"
#include <cstddef>
#include <limits.h>

template <typename T>

Array<T>::Array(){
	this->_array = new T[0];
	this->_size = 0;
}

template <typename T>

Array<T>::Array(unsigned int n){
	if (static_cast<int>(n) < 0)
		throw (Array<T>::BadIndex());
	this->_array = new T[n];
	this->_size = n;
	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = static_cast<T>(NULL);
}

template <typename T>

Array<T>::~Array(){
	delete [] (this->_array);
}

template <typename T>

Array<T>::Array(const Array &copy){
	this->_size = copy._size;
	this->_array = new T[copy._size];
	for (unsigned int i = 0; i < copy._size; i++)
		this->_array[i] = copy._array[i];

}

template <typename T>

Array<T> & Array<T>::operator=(const Array<T> &copy){
	if (&copy != this)
	{
		if (this->_array)
			delete [] (this->_array);
		this->_array = new T[copy._size];
		this->_size = copy._size;
		for (unsigned int i = 0; i < copy._size; i++)
			this->_array[i] = copy._array[i];
	}
	return (*this);
}

template <typename T>

unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
const char * Array<T>::BadIndex::what(void) const throw()
{
	return ("Array::BadIndexException");
}

template <typename T>

T  &Array<T>::operator[](unsigned int index)
{
	if (static_cast<int>(index) < 0 || static_cast<int>(index) > static_cast<int>(this->_size) - 1)
		throw (Array<T>::BadIndex());
	return (this->_array[index]);
}

#endif
