/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekharjo <sekharjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:49:41 by sekharjo          #+#    #+#             */
/*   Updated: 2022/02/16 12:31:47 by sekharjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->m_num = 0;
}

void	PhoneBook::addContact(void)
{
	if (this->m_num == 8)
		this->m_num = 0;
	if (this->m_contact[this->m_num].fillInfo(this->m_num + 1))
		this->m_num++;
}

void	PhoneBook::showPreview(void)
{
	std::cout << "-------------------------------------------\n";
	std::cout << "     Index|First name| Last Name|  Nickname\n";
	std::cout << "-------------------------------------------\n";
	for (int i = 0; i < this->m_num; i++)
		this->m_contact[i].printPreview();
	std::cout << "-------------------------------------------\n";
}

void	PhoneBook::searchContact(void)
{
	int index;
	std::string buf;

	if (this->m_num == 0)
		std::cout << "! Add at least one contact !\n";
	else {
		this->showPreview();
		while (1)
		{
			std::cout << "\n* Enter Index to display contact or 0 to Exit *\n>";
			std::cin >> index;
			if (index < 0 || index > this->m_num) {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "! Wrong Index !\n";
				continue ;
			}
			else {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (index > 0)
					this->m_contact[index - 1].showContact();
				break ;
			}
		}
	}
}