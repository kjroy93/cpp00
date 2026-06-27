/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 02:15:39 by kjroydev          #+#    #+#             */
/*   Updated: 2026/06/27 02:39:05 by kjroydev         ###   ########.fr       */
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

std::string	PhoneBook::cleanIndex(int i)
{
	std::string			s;
	std::stringstream	index;

	index << i + 1;
	s = index.str();
	return (s);
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
