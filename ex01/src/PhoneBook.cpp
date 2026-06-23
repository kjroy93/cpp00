/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:27:44 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/23 19:51:45 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::eofCheck()
{
	if (std::cin.eof())
		exit(0);
}

std::string	PhoneBook::cleanIndex(int i)
{
	std::string			s;
	std::stringstream	index;

	index << i + 1;
	s = index.str();
	return (s);
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
	std::cout << "|" << std::endl;
}

void	PhoneBook::printColumn(const std::string& c)
{
	if (c == "SEARCH")
	{
		std::cout << "|"
		<< std::setw(10) << format("Index")		<< "|"
		<< std::setw(10) << format("Name")		<< "|"
		<< std::setw(10) << format("Last Name")	<< "|"
		<< std::setw(10) << format("Nickname")	<< "|"
		<< std::endl;
	}
	else
	{
		std::cout << "|"
		<< std::setw(10) << format("Index")			<< "|"
		<< std::setw(10) << format("Name")			<< "|"
		<< std::setw(10) << format("Last Name")		<< "|"
		<< std::setw(10) << format("Nickname")		<< "|"
		<< std::setw(10) << format("Phone")			<< "|"
		<< std::setw(10) << format("Secret")		<< "|"
		<< std::endl;
	}
}

void	PhoneBook::print(const std::string& s)
{
	std::cout << "|" << std::setw(10) << s;
}

std::string	PhoneBook::format(std::string info)
{
	std::string	word;
	size_t		str_len;

	str_len = info.size();
	if (str_len > 9)
	{
		word = info.substr(0, 9);
		word.append(".");
		return (word);
	}
	return (info);
}

void	PhoneBook::printResult(int i)
{
	std::cout << "First Name: "		<< contacts_[i].getFirstName()	<< "\n" << std::endl;
	std::cout << "Last Name: "		<< contacts_[i].getLastName()	<< "\n" << std::endl;
	std::cout << "Nick Name: "		<< contacts_[i].getNickName()	<< "\n" << std::endl;
	std::cout << "Phone: "			<< contacts_[i].getNumber()		<< "\n" << std::endl;
	std::cout << "Secret: "			<< contacts_[i].getSecret()		<< "\n" << std::endl;	
}

void	PhoneBook::search(int size)
{
	int	index;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	this->printColumn("SEARCH");
	for (int i = 0; i < size; i++)
		this->printRow(i, "SEARCH");
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (true)
	{
		std::cout << "Please type a valid index" << std::endl;
		std::cin >> index;
		index -= 1;
		this->eofCheck();
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(255, '\n');
			std::cout << "Invalid input (not a number)" << std::endl;
			continue ;
		}
		if (index < 0 || index >= size)
		{
			std::cout << "Invalid index" << std::endl;
			continue ;
		}
		break ;
	}
	this->printResult(index);
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

int	PhoneBook::getIndex()
{
	return (this->i);
}

void	PhoneBook::setIndex(int num)
{
	this->i = num;
}

void	PhoneBook::addContact()
{
	int			i;
	int			size;
	std::string secret;
	std::string number;
	std::string last_name;
	std::string nick_name;
	std::string first_name;

	i = this->getIndex() % 8;
	std::cout << "Please enter the first name of you new contact" << std::endl;
	std::cin.ignore(255, '\n');
	std::getline(std::cin, first_name);
	this->eofCheck();
	std::cout << "Please enter the last name of your new contact" << std::endl;
	std::getline(std::cin, last_name);
	this->eofCheck();
	std::cout << "Enter a nickname for your new contact" << std::endl;
	std::getline(std::cin, nick_name);
	this->eofCheck();
	std::cout << "Please type the phone number" << std::endl;
	std::getline(std::cin, number);
	this->eofCheck();
	std::cout << "You know a juicy secret about your new contact ^^?" << std::endl;
	std::getline(std::cin, secret);
	this->eofCheck();
	contacts_[i].setContact(first_name, last_name, nick_name, number, secret);
	this->setIndex(this->getIndex() + 1);
	size = this->getIndex();
	if (size > 8)
		size = 8;
	this->table(size);
}
