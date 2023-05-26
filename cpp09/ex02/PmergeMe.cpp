#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <ctime>
#include <iostream>

void PmergeMe::start_algorithm(int argc, char **argv)
{
	std::vector<int> vector;
	clock_t start_vector;
	clock_t start_deque;
	std::deque<int> deque;
	clock_t end_vector;
	clock_t end_deque;

	insert_in_container(vector, argc, argv);
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	start_vector = clock();
	merge_sort(vector);
	end_vector = clock();
	std::cout << "After: ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	insert_in_container(deque, argc, argv);
	start_deque = clock();
	merge_sort(deque);
	end_deque = clock();
	std::cout << "Vector sorted: " << is_sorted(vector) << "\nTime to process a range of " << argc - 1 << " with a vector : " << std::fixed << (end_vector - start_vector) / (double)CLOCKS_PER_SEC << "\n";
	std::cout  << "Deque sorted: " << is_sorted(deque) << "\nTime to process a range of " << argc - 1 << " with a deque : " << std::fixed << (end_deque - start_deque) / (double)CLOCKS_PER_SEC << "\n";

}
