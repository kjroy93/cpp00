/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:21:04 by kmarrero          #+#    #+#             */
/*   Updated: 2026/06/26 22:57:00 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::getIndex()
{
	return (this->i);
}

void	PhoneBook::setIndex(int num)
{
	this->i = num;
}

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
	std::string	info;

	std::cout << "First Name: "		<< contacts_[i].getFirstName()	<< "\n" << std::endl;
	std::cout << "Last Name: "		<< contacts_[i].getLastName()	<< "\n" << std::endl;
	std::cout << "Nick Name: "		<< contacts_[i].getNickName()	<< "\n" << std::endl;
	std::cout << "Phone: "			<< contacts_[i].getNumber()		<< "\n" << std::endl;
	std::cout << "Secret: "			<< contacts_[i].getSecret()		<< "\n" << std::endl;	
}

void	PhoneBook::search(int size)
{
	std::stringstream	ss;
	std::string			line;
	std::string			info;
	int					index;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	this->printColumn("SEARCH");
	for (int i = 0; i < size; i++)
		this->printRow(i, "SEARCH");
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	if (size == 0)
	{
		std::cout << "No info to show."
		<< " Please, add one contact at least" << std::endl;
		return ;
	}
	while (true)
	{
		std::cout << "Please type a valid index" << std::endl;
		std::getline(std::cin, line);
		this->eofCheck();
		if (line.find_first_not_of(" \t") == std::string::npos)
		{
			std::cout << "Invalid input" << std::endl;
			return ;
		}
		ss.clear();
		ss.str("");
		ss << line;
		ss >> index;
		if (ss.fail() || !ss.eof())
		{
			std::cout << "Invalid input" << std::endl;
			return ;
		}
		break ;
	}
	index -= 1;
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

bool	PhoneBook::isValidEntry(std::string& entry)
{
	if (entry.empty())
		return (false);
	for (size_t i = 0; i < entry.size(); i++)
	{
		if (!std::isprint(static_cast<unsigned char>(entry[i])))
		{
			std::cout << "Character is not printable" << std::endl;
			return (false);
		}
		if (!std::isspace(static_cast<unsigned char>(entry[i])))
			return (true);
	}
	return (false);
}

std::string	PhoneBook::processEntry(const std::string& prompt, std::string& entry)
{
	while(true)
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, entry);
		if (std::cin.eof())
			return ("");
		if (this->isValidEntry(entry))
			return (entry);
		std::cout << "Field cannot be empty or have only white spaces" << std::endl;
	}
}

std::string	PhoneBook::processNumber(const std::string& prompt)
{
	bool		valid;
	size_t		start;
	std::string	entry;

	while (true)
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, entry);
		this->eofCheck();
		if (entry.empty())
		{
			std::cout << "Phone number cannot be empty" << std::endl;
			continue ;
		}
		start = 0;
		if (entry[0] == '+')
			start = 1;
		valid = true;
		for (size_t i = start; i < entry.size(); ++i)
		{
			if (!std::isdigit(static_cast<unsigned char>(entry[i])))
			{
				valid = false;
				this->eofCheck();
				break ;
			}
		}
		if (valid && start != entry.size())
			return (entry);
		std::cout << "Invalid input. Use only digits."
		<< " You can add '+' first, if needed" << std::endl;
	}
}

void	PhoneBook::addContact()
{
	int					i;
	int					size;
	std::string 		secret;
	std::string 		number;
	std::string 		last_name;
	std::string 		nick_name;
	std::string 		first_name;

	i = this->getIndex() % 8;
	this->processEntry("Please enter the first name of you new contact", first_name);
	this->eofCheck();
	this->processEntry("Please enter the last name of you new contact", last_name);
	this->eofCheck();
	this->processEntry("Enter a nickname for your new contact", nick_name);
	this->eofCheck();
	number = this->processNumber("Please type the phone number");
	this->eofCheck();
	this->processEntry("You know a juicy secret about your new contact ^^?", secret);
	this->eofCheck();
	contacts_[i].setContact(first_name, last_name, nick_name, number, secret);
	this->setIndex(this->getIndex() + 1);
	size = this->getIndex();
	if (size > 8)
		size = 8;
	this->table(size);
}
