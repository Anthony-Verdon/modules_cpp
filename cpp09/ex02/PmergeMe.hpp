#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iterator>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define INSERT_BLOCK 2

class PmergeMe
{
	 public:
		 static void start_algorithm(int argc, char **argv);
		 
		 template <typename T>
		 static void insert_in_container(T & container, int argc, char **argv)
		 {
			for (int i = 1; i < argc; i++)
			{
				container.push_back(strtol(argv[i], NULL, 10));
			}
		 }
		 
		 template <typename T>
		 static void insert_sort(T & container)
		 {
			int	nb_tmp;
			for (size_t i = 0; i < container.size(); i++)
			{
				for (size_t j = i; j < container.size() - 1; j++)
				{
					if (container[j] > container[j + 1])
					{
						while (container[j] > container[j + 1])
						{
							nb_tmp = container[j];
							container[j] = container[j + 1];
							container[j + 1] = nb_tmp;
							if (j != 0)
								j--;
							else
								break;
						}
						break;
					}
				}
			}
		 }
		 
		 template <typename T>
		 static void merge_sort(T & container)
		 {
			if (container.size() < INSERT_BLOCK)
				insert_sort(container);
			else
			{
				T container1;
				T container2;
				T container3;
				for (size_t i = 0; i < container.size() / 2; i++)
					container1.push_back(container[i]);
				merge_sort(container1);
				for (size_t i = container.size() / 2; i < container.size(); i++)
					container2.push_back(container[i]);
				merge_sort(container2);
				std::merge(container1.begin(), container1.end(),
						container2.begin(), container2.end(), std::back_inserter(container3));
				container = container3;
			}
		 }

		template <typename T>
		static std::string is_sorted(T container)
		{
			for (size_t i = 0; i < container.size() - 1; i++)
			{
				if (container[i] > container[i + 1])
					return ("false");
			}
			return ("true");
		}

	 private:
		PmergeMe();
		~PmergeMe();
		PmergeMe (const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe&);
		
};

#endif
