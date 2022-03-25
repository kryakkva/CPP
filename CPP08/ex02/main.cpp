#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack top:	" << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack size:	" << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(0);
		mstack.push(737);

		MutantStack<int>::iterator it_b	= mstack.begin();
		MutantStack<int>::iterator it_e	= mstack.end();

		++it_b;
		--it_b;

		while (it_b != it_e) {
			std::cout << *it_b << " ";
			++it_b;
		}
		std::cout << std::endl;
		std::cout << "_____________________________________" << std::endl;

		std::stack<int>	s(mstack);
		std::cout << "mstack top mstack:	" << mstack.top() << std::endl;
		std::cout << "mstack top s:		" << s.top() << std::endl;
	}
	std::cout << "_____________________________________" << std::endl;
	{
		MutantStack<int> mstack_r;

		mstack_r.push(11);
		mstack_r.push(22);
		mstack_r.push(33);
		mstack_r.push(44);
		mstack_r.push(55);
		mstack_r.push(66);
		mstack_r.push(88);

		MutantStack<int>::reverse_iterator it_rb		= mstack_r.rbegin();
		MutantStack<int>::reverse_iterator it_re	= mstack_r.rend();
		while (it_rb != it_re)
		{
			std::cout << *it_rb << " ";
			++it_rb;
		}
		std::cout << std::endl;
	}
	return (0);
}