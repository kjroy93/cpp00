/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:21:04 by kmarrero          #+#    #+#             */
/*   Updated: 2026/06/27 04:54:23 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
		if (!std::getline(std::cin, line))
			return ;
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
	if (index < 0 || index >= size)
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	this->printResult(index);
}

bool	PhoneBook::isValidEntry(std::string& entry)
{
	unsigned char	c;
	bool			flag;

	flag = false;
	if (entry.empty())
		return (false);
	for (size_t i = 0; i < entry.size(); i++)
	{
		c = static_cast<unsigned char>(entry[i]);
		if (!std::isprint(c))
		{
			std::cout << "A character is not printable" << std::endl;
			return (false);
		}
		if (!std::isspace(c))
			flag = true;
	}
	if (!flag)
	{
		std::cout << "User entry only have white spaces" << std::endl;
		return (false);
	}
	return (true);
}

bool	PhoneBook::processEntry(const std::string& prompt, std::string& entry)
{
	while(true)
	{
		std::cout << prompt << std::endl;
		if (!std::getline(std::cin, entry))
			return (false);
		if (this->isValidEntry(entry))
			return (true);
		std::cout << "Field cannot be empty, "
		<< "have only white spaces "
		<< "or contain characters only available in UTF-8" << std::endl;
	}
}

bool PhoneBook::processNumber(const std::string& prompt, std::string& number)
{
	size_t		i;
	bool		ok;
	std::string entry;

	while (true)
	{
		std::cout << prompt << std::endl;
		if (!std::getline(std::cin, entry))
			return (false);
		if (entry.empty())
		{
			std::cout << "Phone number cannot be empty" << std::endl;
			continue ;
		}
		i = 0;
		if (entry[0] == '+')
		{
			if (entry.size() == 1)
			{
				std::cout << "Invalid input. "
				<< "Phone number must have numbers, not just +" << std::endl;
				continue ;
			}
			i = 1;
		}
		ok = true;
		for (; i < entry.size(); i++)
		{
			if (!std::isdigit(static_cast<unsigned char>(entry[i])))
			{
				ok = false;
				break ;
			}
		}
		if (!ok)
		{
			std::cout << "Invalid input" << std::endl;
			continue ;
		}
		number = entry;
		return (true);
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
	if (!this->processEntry("Please enter the first name of you new contact", first_name))
		return ;
	if (!this->processEntry("Please enter the last name of you new contact", last_name))
		return ;
	if (!this->processEntry("Enter a nickname for your new contact", nick_name))
		return ;
	if (!this->processNumber("Please type the phone number", number))
		return ;
	if (!this->processEntry("You know a juicy secret about your new contact ^^?", secret))
		return ;
	contacts_[i].setContact(first_name, last_name, nick_name, number, secret);
	this->setIndex(this->getIndex() + 1);
	size = this->getIndex();
	if (size > 8)
		size = 8;
	this->table(size);
}
