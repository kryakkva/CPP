#include <iostream>
#include <fstream>

int ft_replace(std::string file, std::string str1, std::string str2)
{
	size_t pos = 0;

	if (!file.size())
		throw ("Wrong file name");
	if (!str1.size() || !str2.size())
		throw ("Strings must not be empty");
	std::ifstream inFile(file);
	if (!inFile)
		throw ("Infile open failed");
	std::ofstream outFile(file + ".replace", std::ios::trunc);
	if (!outFile)
		throw ("Outfile open failed");
	std::string buf;
	std::getline(inFile, buf, '\0');
	pos = buf.find(str1);
	while (pos != std::string::npos)
	{
		buf.erase(pos, str1.size());
		buf.insert(pos, str2);
		pos = buf.find(str1, pos + str2.size());
	}
	outFile << buf;
	outFile.close();
	inFile.close();
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cerr << "Error: to use run: " << argv[0]
					<< " <filename> <str1> <str2>" << std::endl;
		return (1);
	}
	try {
		return (ft_replace(argv[1], argv[2], argv[3]));
	}
	catch(char const *err) {
		std::cerr << "Error: " << err << '\n';
	}
	return (1);
}
