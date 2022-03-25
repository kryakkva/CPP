#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5
int main(int, char**)
{
	try
	{
		Array<int> numbers(0);	/* code */
		std::cout << &numbers << " numbers size = " << numbers.size() << std::endl;
		numbers[0] = 12345;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Array<int> numbers(MAX_VAL);
	Array<std::string> strings(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		strings[i] = std::to_string(value) + "_STRING";
		std::cout << numbers[i] << '\t';
		std::cout << mirror[i] << '\t';
		std::cout << strings[i] << std::endl;
	}
	//SCOPE
	{
		std::cout << std::endl;
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << "numbers size = " << numbers.size() << std::endl;
		test[0] = 0;
		std::cout << tmp[0] << '\t';
		std::cout << test[0] << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
		std::cout << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		std::cout << std::endl;
	try
	{
		strings[MAX_VAL] = "OVER";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		std::cout << std::endl;
	Array<int> tmp = numbers;
	Array<std::string> tmp_str = strings;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
		tmp_str[i] = std::to_string(rand()) + "_OTHER_STR";
		std::cout << numbers[i] << "\t\t";
		std::cout << tmp[i] << std::endl;
		std::cout << strings[i] << '\t';
		std::cout << tmp_str[i] << std::endl;
	}
		std::cout << std::endl;
	delete [] mirror;
	return 0;
}