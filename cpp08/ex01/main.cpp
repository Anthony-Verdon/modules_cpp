#include "Span.hpp"
#include <iostream>
#include <climits>

int main()
{
	{
		std::cout << "Subject Main:" <<std::endl;
		Span sp = Span(10);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
    {
        std::cout << "My Main:" <<std::endl;
		
		Span span = Span(2);

		span.addNumber(INT_MIN);
		span.addNumber(INT_MAX);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
        
		std::vector<int> test;

        test.push_back(10);
        test.push_back(20);
        test.push_back(30);
        test.push_back(40);
        test.push_back(50);
        test.push_back(60);
        Span sp = Span(7);

        try{
            sp.addNumber(test.begin(), test.end());
        } catch (std::exception & e){
            std::cout << e.what() << std::endl;
        }
        try{
            sp.addNumber(test.begin(), test.end());
        } catch (std::exception & e){
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "longest span: " << sp.longestSpan() << std::endl;
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
        {
            Span ap = Span(100000000);
            try{
                for (int i = 0; i < 1000; i++)
                    ap.addNumber(test.begin(), test.end());
            } catch (std::exception & e){
                std::cout << e.what() << std::endl;
            }
            try {
                ap.addNumber(5);
                std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
                std::cout << "longest span: " << sp.longestSpan() << std::endl;
            } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
	return 0;
}
