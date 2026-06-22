/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:27:44 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/22 21:16:55 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::getIndex()
{
	return (i);
}

void	PhoneBook::setIndex(int num)
{
	i = num;
}

void	PhoneBook::print(const std::string &s)
{
	std::cout << "|" << std::setw(10) << s;
}

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
	std::cout << "|";
	std::cout << std::endl;
}

std::string	PhoneBook::format(std::string info)
{
	size_t		str_len;
	std::string	word;

	str_len = info.size();
	if (str_len > 9)
	{
		word = info.substr(0, 9);
		word.append(".");
		return (word);
	}
	return (info);
}

std::string	PhoneBook::cleanIndex(int i)
{
	std::stringstream	index;
	std::string			s;

	index << i;
	s = index.str();
	return (s);
}

void	PhoneBook::search()
{
	int	size;
	int	index;

	size = this->getIndex() % 8;
	std::cout << "|"
	<< std::setw(10) << "Index"		<< "|"
	<< std::setw(10) << "Name"		<< "|"
	<< std::setw(10) << "Last_Name"	<< "|"
	<< std::setw(10) << "Nickname"	<< "|"
	<< std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < size; i++)
		printRow(i, "SEARCH");
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (true)
	{
		std::cout << "Please type a valid index" << std::endl;
		std::cin >> index;

		if (index < 0 || index >= size || index > 8)
		{
			std::cout << "Invalid index" << std::endl;
			std::cin.clear();
			continue ;
		}
		break ;
	}
	std::cout << "First Name: "		<< contacts_[index].getFirstName()	<< "\n";
	std::cout << "Last Name: "		<< contacts_[index].getLastName()	<< "\n";
	std::cout << "Nick Name: "		<< contacts_[index].getNickName()	<< "\n";
	std::cout << "Phone number: "	<< contacts_[index].getNumber()		<< "\n";
	std::cout << "Dark Secret: "	<< contacts_[index].getSecret()		<< "\n";
}

void	PhoneBook::table(int &n)
{
	std::string	s;
	int	size;

	size = this->getIndex() % 8;
	std::cout << "|"
	<< std::setw(10) << "Index"			<< "|"
	<< std::setw(10) << "Name"			<< "|"
	<< std::setw(10) << "Last_Name"		<< "|"
	<< std::setw(10) << "Nickname"		<< "|"
	<< std::setw(10) << "Phone Number"	<< "|"
	<< std::setw(10) << "Dark Secret"	<< "|"
	<< std::endl;
	std::cout << "+----------+----------+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < n; i++)
		printRow(i, "TABLE");
	std::cout << "+----------+----------+----------+----------+----------+----------+" << std::endl;
}

void	PhoneBook::addContact()
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string number;
	std::string secret;
	int			i;
	int			size;

	i = this->getIndex() % 8;
	std::cout << "Please enter the first name of you new contact" << std::endl;
	std::cin >> first_name;
	std::cout << "Please enter the last name of your new contact" << std::endl;
	std::cin >> last_name;
	std::cout << "Enter a nickname for your new contact" << std::endl;
	std::cin >> nick_name;
	std::cout << "Please type the phone number" << std::endl;
	std::cin >> number;
	std::cout << "You know a juicy secret about your new contact ^^?" << std::endl;
	std::cin >> secret;

	contacts_[i].setContact(first_name, last_name, nick_name, number, secret);

	this->setIndex(this->getIndex() + 1);

	size = this->getIndex();
	table(size);
}
