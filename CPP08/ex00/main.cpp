#include <iostream>
#include <vector>
#include <deque>
#include <list>

#include "easyfind.hpp"

int main() {
	{
		std::vector<int>::iterator v_it;
		std::vector<int> vector;
		int i;
		int nb = 10;
		std::cout << "nb: " << nb << std::endl;
		for (i = 2; i < 12; ++i)
			vector.push_back(i);
		for (v_it = vector.begin(); v_it != vector.end(); ++v_it)
			std::cout << *v_it << ' ';
		std::cout << std::endl;
		try {
			i = easyfind(vector, nb);
			std::cout << "easyfind: " << i << std::endl;
		} 
		catch (std::exception &ex) {
			std::cerr << ex.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::deque<int> deq;
		std::deque<int>::iterator v_it;
		int i;
		int nb = 6;
		 for (int count = 0; count < 4; ++count)
		{
			deq.push_back(count);
			deq.push_front(10 - count);
		}
		std::cout << "nb: " << nb << std::endl;
		for (v_it = deq.begin(); v_it != deq.end(); ++v_it)
			std::cout << *v_it << ' ';
		std::cout << std::endl;
		try {
			i = easyfind(deq, nb);
			std::cout << "easyfind: " << i << std::endl;
		} 
		catch (std::exception &ex) {
			std::cerr << ex.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::list<int> list;
		std::list<int>::iterator v_it;
		int i;
		int nb = 100;
		 for (int count = 0; count < 4; ++count)
		{
			list.push_back(100 - count);
			list.push_front(count);
		}
		std::cout << "nb: " << nb << std::endl;
		for (v_it = list.begin(); v_it != list.end(); ++v_it)
			std::cout << *v_it << ' ';
		std::cout << std::endl;
		try {
			i = easyfind(list, nb);
			std::cout << "easyfind: " << i << std::endl;
		} 
		catch (std::exception &ex) {
			std::cerr << ex.what() << std::endl;
		}
	}

	return 0;
}