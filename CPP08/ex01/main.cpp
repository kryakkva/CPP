#include "Span.hpp"

int main()
{
	int i;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try {
		sp.addNumber(19);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for ( i = 0; i < 6; i++)
	{
		try
		{
			std::cout << sp[i] << " ";
		}
		catch(const std::exception& e)
		{
			std::cout << std::endl;
			std::cerr << e.what() << '\n';
		}
		
	}
	
	std::cout << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "____________________________________\n" << std::endl;
	{
		try
		{
			std::list<int> tmp;
			for (i = 0; i < 10000; ++i)
				tmp.push_front(i);

			Span sp_arr = Span(10000);
			sp_arr.addNumber(tmp.begin(), tmp.end());
			// std::cout << "TMP_SIZE\t" << tmp.size() << std::endl;
			// std::cout << "SIZE\t" << sp_arr.getSize() << std::endl;
			// std::cout << "F_SIZE\t" << sp_arr.getFSize() << std::endl;
			for ( i = 0; i < 5; i++)
			{
				std::cout << sp_arr[i] << " ";
			}
			std::cout << "... ";
			for ( i = 9990; i < 10000; i++)
			{
				std::cout << sp_arr[i] << " ";
			}
			std::cout << std::endl;
			
			std::cout << "shortest:	" << sp_arr.shortestSpan() << std::endl;
			std::cout << "longest:	" << sp_arr.longestSpan() << std::endl;
			for ( i = 0; i < 5; i++)
			{
				std::cout << sp_arr[i] << " ";
			}
			std::cout << "... ";
			for ( i = 9990; i < 10000; i++)
			{
				std::cout << sp_arr[i] << " ";
			}
			std::cout << std::endl;
		}
		catch (const std::exception &ex) {
			std::cout << ex.what() <<std::endl;
		}
	}
	
	return 0;
}