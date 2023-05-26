#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>

typename T::iterator easyfind(T container, int occur)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), occur);
	if (it == container.end())
		std::cout << occur << " not find\n";
	else
		std::cout << occur << " find\n";
	return (it);
}

#endif
