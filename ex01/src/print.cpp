/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:36:44 by kmarrero          #+#    #+#             */
/*   Updated: 2026/06/29 12:36:46 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::printRow(int i, std::string command)
{
	std::string	s;

	s = cleanIndex(i);
	if (command == "SEARCH")
	{
		print(format(s));
		print(format(this->contacts_[i].getFirstName()));
		print(format(this->contacts_[i].getLastName()));
		print(format(this->contacts_[i].getNickName()));
	}
	else
	{
		print(format(s));
		print(format(this->contacts_[i].getFirstName()));
		print(format(this->contacts_[i].getLastName()));
		print(format(this->contacts_[i].getNickName()));
		print(format(this->contacts_[i].getNumber()));
		print(format(this->contacts_[i].getSecret()));
	}
	std::cout << "|" << std::endl;
}

void	PhoneBook::printColumn(const std::string& c)
{
	if (c == "SEARCH")
	{
		std::cout << "|"
		<< std::setw(10) << "Index"		<< "|"
		<< std::setw(10) << "Name"		<< "|"
		<< std::setw(10) << "Last Name"	<< "|"
		<< std::setw(10) << "Nickname"	<< "|"
		<< std::endl;
	}
	else
	{
		std::cout << "|"
		<< std::setw(10) << "Index"			<< "|"
		<< std::setw(10) << "Name"			<< "|"
		<< std::setw(10) << "Last Name"		<< "|"
		<< std::setw(10) << "Nickname"		<< "|"
		<< std::setw(10) << "Phone"			<< "|"
		<< std::setw(10) << "Secret"		<< "|"
		<< std::endl;
	}
}

void	PhoneBook::print(const std::string& s)
{
	std::cout << "|" << std::setw(10) << s;
}

void	PhoneBook::printResult(int i)
{
	std::string	info;

	std::cout << "First Name: "		<< contacts_[i].getFirstName()	<< "\n" << std::endl;
	std::cout << "Last Name: "		<< contacts_[i].getLastName()	<< "\n" << std::endl;
	std::cout << "Nick Name: "		<< contacts_[i].getNickName()	<< "\n" << std::endl;
	std::cout << "Phone: "			<< contacts_[i].getNumber()		<< "\n" << std::endl;
	std::cout << "Secret: "			<< contacts_[i].getSecret()		<< "\n" << std::endl;	
}

void	PhoneBook::table(int size)
{
	std::string	s;

	std::cout << "+----------+----------+----------+----------+----------+----------+" << std::endl;
	this->printColumn("TABLE");
	for (int i = 0; i < size; i++)
		this->printRow(i, "TABLE");
	std::cout << "+----------+----------+----------+----------+----------+----------+" << std::endl;
}
