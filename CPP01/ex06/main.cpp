#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen karen;

	if (argc != 2){
		std::cerr << "Error: to use run: " << argv[0] << " <complaint>" << std::endl;
		std::cerr << "Significant complaints \"DEBUG\", \"INFO\", \"WARNING\" or \"ERROR\"" << std::endl;
		return (1);
	}
	karen.complain(argv[1]);
	
	return (0);
}
