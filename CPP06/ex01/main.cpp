#include <iostream>

typedef struct sData
{
	std::string _name;
	int _i;
}	Data;


Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

int main(void)
{
	Data original;
	Data *copy;

	original._name = "Data";
	original._i = 123;

	std::cout << "Original:\t" << original._name << " " << original._i << std::endl;
	copy = deserialize(serialize(&original));
	std::cout << "Copy:\t\t" << copy->_name << " " << copy->_i << std::endl;
	
	return 0;
}
