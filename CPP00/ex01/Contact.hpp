#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
private:
	static std::string	fieldsName[5];
	std::string			fieldsVal[5];
	int					m_index;
public:
	Contact();

	bool	fillInfo(int index);
	void	printPreview();
	void	showContact();
};

#endif