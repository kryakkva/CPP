#include "Contact.hpp"

std::string Contact::fieldsName[5] = {
	"First Name: ",
	"Last Name: ",
	"Nickname: ",
	"Phone number: ",
	"Darkest secret: "
};

Contact::Contact()
{
	for (int i = 0; i < 5; i++)
		this->fieldsVal[i] = std::string();
}

bool Contact::fillInfo(int index)
{
	size_t len = 0;

	this->m_index = index;
	for (int i = 0; i < 5; i++) {
		std::cout << this->fieldsName[i];
		std::getline(std::cin, this->fieldsVal[i]);
		len = this->fieldsVal[i].size();
		if (!len) {
			std::cout << "заполните поле " << fieldsName[i] << std::endl;
			i--;
		}
	}
	std::cout << "\n* New contact \"" << fieldsVal[0] <<"\" added *\n\n";
	return (true);
}

void Contact::printPreview(void)
{
	
	std::cout << std::setw(10) << this->m_index;
	for (size_t i = 0; i < 3; i++)
	{
		if (this->fieldsVal[i].size() > 10)
			std::cout << "|" << this->fieldsVal[i].substr(0,9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->fieldsVal[i];	
	}
	std::cout << std::endl;
}

void Contact::showContact(void)
{
	for (size_t i = 0; i < 5; i++)
		std::cout << this->fieldsName[i] << this->fieldsVal[i] << std::endl;
}