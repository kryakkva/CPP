#include <iostream>

void ft_convert(std::string str)
{
	// char
	try
	{
		char c = static_cast<char>(stoi(str));
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "char: impossible" << std::endl;
	}
	// int
	try
	{
		int i = static_cast<int>(stoi(str));
		std::cout << "int: " << i << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "int: impossible" << std::endl;
	}
	// float
	try
	{
		float f = static_cast<float>(stof(str));
		std::cout.precision(1);
		std::cout << std::fixed << "float: " << f << "f" << std::endl;
	}
	catch (std::out_of_range &out) {
		std::cerr << out.what() << '\n';
		std::cout << "float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "float: impossible" << std::endl;
	}
	// double
	try
	{
		double d = static_cast<double>(stod(str));
		std::cout.precision(1);
		std::cout << std::fixed << "double: " << d << std::endl;
	}
	catch (std::out_of_range &out) {
		std::cerr << out.what() << '\n';
		std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "double: impossible" << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "Input ONE argument to be converted" << std::endl;
	else {
		ft_convert(argv[1]);
	}
	return 0;
}
