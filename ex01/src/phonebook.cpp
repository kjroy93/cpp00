/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:27:44 by kjroydev          #+#    #+#             */
/*   Updated: 2026/05/24 21:09:46 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	PhoneBook::get_index()
{
	return (i);
}

void	PhoneBook::set_index(int num)
{
	i = num;
}

void	PhoneBook::print(const std::string &s)
{
	std::cout << "|" << std::setw(10) << s;
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

std::string	PhoneBook::clean_index(int i)
{
	std::stringstream	index;
	std::string			s;

	index << i;
	s = index.str();
	return (s);
}

void	PhoneBook::search()
{
	std::string	s;
	int			i;
	int			y;

	i = PhoneBook::get_index() % 8;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int y = 0; y < i; y++)
	{
		s = clean_index(y);
		print(format(s));
		print(format(PhoneBook::contacts_[y].get_first_name()));
		print(format(PhoneBook::contacts_[y].get_last_name()));
		print(format(PhoneBook::contacts_[y].get_nickname()));
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	while (true)
	{
		std::cout << "Please type a valid index to show you a specific contact" << std::endl;
		std::cin >> y;
		if (y > i)
		{
			std::cout << "Invalid index" << std::endl;
			continue ;
		}
		else
			break ;
	}
	s = clean_index(y);
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	print(format(s));
	print(format(PhoneBook::contacts_[y].get_first_name()));
	print(format(PhoneBook::contacts_[y].get_last_name()));
	print(format(PhoneBook::contacts_[y].get_nickname()));
	std::cout << "|";
	std::cout << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void	PhoneBook::table(int &n)
{
	std::string	s;

	std::cout << "+----------+----------+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < n; i++)
	{
		s = clean_index(i);
		print(format(s));
		print(format(PhoneBook::contacts_[i].get_first_name()));
		print(format(PhoneBook::contacts_[i].get_last_name()));
		print(format(PhoneBook::contacts_[i].get_nickname()));
		print(format(PhoneBook::contacts_[i].get_number()));
		print(format(PhoneBook::contacts_[i].get_secret()));
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "+----------+----------+----------+----------+----------+----------+" << std::endl;
}

void	PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string number;
	std::string secret;
	int			i;
	int			size;

	i = PhoneBook::get_index() % 8;
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

	contacts_[i].set_contact(
	first_name,
	last_name,
	nick_name,
	number,
	secret);

	PhoneBook::set_index(PhoneBook::get_index() + 1);

	size = PhoneBook::get_index();
	table(size);
}
