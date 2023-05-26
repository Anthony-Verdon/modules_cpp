#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T>
{
	 public:
		MutantStack();
		~MutantStack();
		MutantStack (const MutantStack &copy);
		MutantStack &operator=(const MutantStack&);
		
		typedef typename container::iterator iterator;
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
	 private:
		
};

#endif
